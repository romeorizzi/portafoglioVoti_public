"""
* user:  VR447268_id713ast
* fname: PIETRO
* lname: TAROCCO
* task:  risparmio
* score: 0.0
* date:  2020-07-14 10:48:08.464489
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jul 14 11:38:51 2020

@author: pietro
"""


def operazione_1(vec, index):
    
    tmp_vec = vec.copy()
    if(vec[index] == 0):
        tmp_vec[index] = 1 
    if(vec[index] == 1): 
        tmp_vec[index] = 0
        
    return tmp_vec

def operazione_2(vec, l, r):
    
    tmp_matrix, line_counter = [[] for _ in range(len(vec))], 0
    
    for i in range(l,r+1):
        if(vec[i]==1):
            tmp_matrix[line_counter].append(vec[i])
        if(vec[i]==0):
            line_counter += 1
    
    return len(list(filter(lambda a: a != [], tmp_matrix)))



if __name__ == "__main__":
    
    file = open("input.txt", 'r')
    firstLine = file.readline().split(" ")
    N = int(firstLine[0]) # total number of lights
    M = int(firstLine[1]) # total number of operations
    matrix = [[]]
    
    for line in file:
        matrix.append(list(map(int, line.split(" "))))
    matrix.pop(0)
    file.close()
    
    results = []
    vec = [0 for i in range(N)]
    
    for i in range(len(matrix)):
        if(matrix[i][0]==1):
            vec = operazione_1(vec, matrix[i][1])
        if(matrix[i][0]==2):
            results.append(operazione_2(vec, matrix[i][1], matrix[i][2]))
            
            
    output = open("output.txt", "w")
    for i in range(results):
        output.write(str(results[i]) + "\n")
        
    output.close()