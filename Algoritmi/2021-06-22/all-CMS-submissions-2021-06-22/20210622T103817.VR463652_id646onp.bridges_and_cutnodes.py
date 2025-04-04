"""
* user:  VR463652_id646onp
* fname: ALEARDO
* lname: LODI
* task:  bridges_and_cutnodes
* score: 0.0
* date:  2021-06-22 10:38:17.866197
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
from __future__ import print_function
import sys
import os

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
                # print("From " + str(start_index) + " to " + str(i) + " per " + str(end_index))

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
