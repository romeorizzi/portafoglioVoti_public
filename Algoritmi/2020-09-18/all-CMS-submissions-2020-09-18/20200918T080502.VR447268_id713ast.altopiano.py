"""
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  altopiano
* score: 25.0
* date:  2020-09-18 08:05:02.984202
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Sep 18 08:13:06 2020

@author: pietro
"""

def file_reading():
    
    file = open("input.txt", "r")
    N, Ops_number = map(int, file.readline().split())
    v = list(map(int, file.readline().split()))
    operations = []
    
    for line in file.readlines():
        operations.append(list((map(int, line.split()))))

    file.close()
    return N, Ops_number, v, operations


def file_writing(result):
    
    file = open("output.txt", "w")
    
    for i in range(len(result)):
        file.write(str(result[i]))
        file.write("\n")
        
    file.close()
    

def fine_max_altopiano(v):
    
    solutions = []
    counter=0
    for i in range(len(v)-1):
        if v[i] == v[i+1]:
            counter += 1
            if counter == 2:
                solutions.append(v[i])
        if v[i] != v[i+1]:
            counter = 0
            
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