"""
* user:  VR463652_id646onp
* fname: ALEARDO
* lname: LODI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 11:07:12.519755
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
from __future__ import print_function
import sys
import copy, json


# if sys.version_info < (3, 0):
#     input = raw_input  # in python2, raw_input svolge la funzione della primitiva input in python3

sys.setrecursionlimit(1000000)

DEBUG = True
DEBUG = False

DEPTH = 0
tipo, V, E = map(int, input().split())  # probem type and number of disks

matrix = [[]] * V
matrix_path = [[]] * V
visited = [False] * E
counter = 0


for i in range(E):
    s, t = map(int, input().split())
    matrix[s] = matrix[s] + [t]
    matrix_path[s] = matrix_path[s] + [t]
    matrix[t] = matrix[t] + [s]


for i in range(V):
    if matrix[i] == []:
        matrix[i] = []


def number_path_two_nodes(start_index, end_index):
    global matrix
    global visited
    global counter
    visited[start_index] = True

    if start_index == end_index:
        counter = counter +1
    else:
        for i in matrix[start_index]:
            if visited[i] == False:

                number_path_two_nodes(i, end_index)
    visited[start_index] = False

if tipo == 1:
    for i in range(V):

        for k in matrix_path[i]:
            number_path_two_nodes(i, k)
            # print("From " + str(i) + " to " + str(k) + " ho " + str(counter))
            if counter == 1:
                print("1")
            else:
                print("0")
            counter = 0
            visited = [False] * E
    exit()


original_matrix = copy.deepcopy(matrix)

def controlla_correlazioni_path(original_target, i):
    global visited
    global counter
    for k in original_target:
        for s in original_target:
            if s != k:
                number_path_two_nodes(s, k)
                if counter == 0:
                    return 1

                counter = 0
                visited = [False] * E

    return 0

if tipo == 2:
    for i in range(V):
        original_target = original_matrix[i]
        matrix = json.loads(json.dumps(original_matrix))
        # matrix = original_matrix[:]

        for k in range(V-1):
            if i in matrix[k]:
                matrix[k].remove(i)

        print(controlla_correlazioni_path(original_target, i))
    exit()

