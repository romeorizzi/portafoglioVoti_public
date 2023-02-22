"""
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:27:16.606581
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

dyn_matrix=[]

f = open("input.txt", "r")
N = int(f.readline())
path= map(int,f.readline().split())
pathInt=[]
for i in path:
    pathInt.append(int(i))
    dyn_matrix.append(-1)

def avanza(indexStart, sum, passo):

    if(indexStart >= N):
        return sum
    sum = pathInt[indexStart]
    if(indexStart+passo<N):
        if(dyn_matrix[indexStart+passo]==-1):
            add1=avanza(indexStart+passo, 0, 2)
            add2=avanza(indexStart+passo, 0, 3)
            dyn_matrix[indexStart+passo]=max(add1,add2)
        return sum+dyn_matrix[indexStart+passo]
    return sum

sum1=avanza(0,0,2)
sum2=avanza(0,0,3)
print(max(sum1,sum2))