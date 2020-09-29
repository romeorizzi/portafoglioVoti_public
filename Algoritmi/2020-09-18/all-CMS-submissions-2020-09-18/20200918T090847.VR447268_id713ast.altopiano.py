"""
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 09:08:47.998252
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 18 08:13:06 2020

@author: pietro
"""
import math

def file_reading():
    
    file = open("input.txt", "r")
    N, M = map(int, file.readline().split())
    v = list(map(int, file.readline().split()))
    # assert N >= 1 and N <= 100000
    # assert M >= 1 and M <= 100000
    operations = []
    
    for line in file.readlines():
        operations.append(list((map(int, line.split()))))

    file.close()
    return N, M, v, operations


def file_writing(result):
    
    file = open("output.txt", "w")
    
    for i in range(len(result)):
        file.write(str(result[i]))
        file.write("\n")
        
    file.close()
    

def fine_max_altopiano(v):
    
    solutions = []
    counterL, counterR, i, j = 0, 0, 0, len(v)-1
    # for i in range(math.ceil(len(v)/2)):
    while i<j:
        if v[i] == v[i+1]:
            counterL += 1
            if counterL == 2:
                solutions.append(v[i])
        if v[j-i] == v[j-1-i]:
            counterR += 1
            if counterR == 2:
                solutions.append(v[j-i])
     
        if v[i] != v[i+1]:
            counterL = 0
            
        if v[j-i] != v[j-1-i]:
            counterR = 0
        i+=1
            
    if len(solutions) > 0:
        return max(solutions)
    else:
        return "NESSUN_ALTOPIANO"

def change_value(v, operation):
    
    v[operation[1]] += operation[2]

    return v


if __name__ == "__main__":
    
    N, Ops_number, v, operations = file_reading()
    result = []
    
    
    for operation in operations:
        if operation[0] == 1:
            v = change_value(v, operation)
        if operation[0] == 2:
            result.append(fine_max_altopiano(v[operation[1]:operation[2]+1]))
            
    file_writing(result)