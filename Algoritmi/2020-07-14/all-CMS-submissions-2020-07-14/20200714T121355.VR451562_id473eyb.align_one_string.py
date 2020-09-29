"""
* user:  VR451562_id473eyb
* fname: FEDERICO
* lname: GIRELLA
* task:  align_one_string
* score: 32.0
* date:  2020-07-14 12:13:55.207638
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
import math

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

sys.setrecursionlimit(10**9)

def possible(i1, i2):
    global N
    global M
    global s1
    global s2
    # to expensive, n*m
    # need to implement it in the memo
    pass

    # # count * in s1:
    # ast = 0
    # for j in range(i1, M):
    #     if s1[j] == '*':
    #         ast += 1
    # # n è di i2
    # #indexes of string 1 and string 2
    # while i2 < N:
    #     for j in range(i1, M):
    #         # check the remaining chars
    #     i2 += 1

# M = 8
# N = 4
# P = [0,1,3,3,2,8,6,7]
# s1 = 'asdfdsdf'
# s2 = 'asdf'

vin = input().rstrip('\n').split(' ')
M = int(vin[0])
N = int(vin[1])
pp = int(vin[2])
s1 = input().rstrip('\n')
s2 = input().rstrip('\n')
P = input().rstrip('\n').split(' ')
for p in range(len(P)):
    P[p] = int(P[p])



if N > M:
    print(-1)
else:
    # memo = [[0 for _ in range(N+2)] for _ in range(M+2)]
    # we only need last row and current

    # initially we have placed all the letters
    c_spazi = [-1 for _ in range(M+1)]
    # -1 indicates that we can't fill that many spaces
    # i = 0
    # while i < len(P): 
    #     # check all options
    #     mini = P[i]
    #     for j in range(1, (i//2)+1):
    #         mini = min(mini, P[i-j] + P[j])
    #     c_spazi[i] = mini
    #     i += 1

    i = 0
    while i < M + 1: 
        # check all options
        mini = 9999
        if i < len(P):
            for j in range(0, (i//2)+1):
                mini = min(mini, P[i-j] + P[j])
            c_spazi[i] = mini
        else:
            # bigger gaps than a single fill can do
            for k in range(0, (i//2) + 1):
                if c_spazi[i-k] != -1:
                    mini = min(c_spazi[k] + c_spazi[i-k], mini)
        c_spazi[i] = mini      
        i += 1

    l_row = [c_spazi[i] for i in range(len(c_spazi)-1, -1, -1)]
    # print(l_row)
    # now let's calculate from last char
    i = N-1
    while i >= 0:
        # bottom up
        row = [-1 for _ in range(M+1)]
        for j in range(i, M+1):
            # left to right
            mini = 999999
            k = j
            while k<M:
                # find next occurrence
                if s2[i] == s1[k] or s1[k]== '*':
                    diff = k-j # spazi da riempire
                    if l_row[k+1] != -1 and c_spazi[diff] != -1:
                        # has to be possible to fill these spaces
                        mini = min(c_spazi[diff]+l_row[k+1], mini)
                k+=1
            if mini != 999999:
                row[j] = mini
        i -= 1
        l_row = row

    print(l_row[0])