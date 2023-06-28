"""
* user:  VR463656
* fname: GIOVANNI
* lname: DANIELI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 13:29:57.111622
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

with open("input.txt", "r") as i_f:
    N,M,PL,PC = map(int,i_f.readline().strip().split())
    COSTI = [[0 for _ in range(N)] for _ in range(M)]
    figli = [[] for _ in range(M)]

    for _ in range(M):
        t, h, c = map(int, i_f.readline().strip().split())
        figli[t].append(h)
        COSTI[t][h] = c



def dfs(node:int, goal:int, l: int, c: int, visitati: list):
    if node == goal and (PL==2 or l % 2 == PL) and (PC==2 or c % 2 == PC):
        return c
    result = []
    for figlio in figli[node]:
        temp = None
        if l == 0:
            visitati = [[[] for _ in range(N)] for _ in range(N)]
            temp = dfs(figlio, goal, l + 1, c + COSTI[node][figlio], visitati)
        else:
            if node not in visitati[figlio]:
                visitati[figlio].append(node)
                temp = dfs(figlio, goal, l + 1, c + COSTI[node][figlio], visitati)
            else:
                return
        if temp:
                result.append(temp)
    if len(result) == 0:
        if l==0:
                return -1
        return

    return min(result)
    



answer = [-1 for _ in range(N)]

for i in range(N):
    answer[i] = dfs(0, i, 0, 0, [0 for _ in range(N)])

with open("output.txt", "w") as o_f:
    for x in answer:
        o_f.write(str(x) + " ")
#print(answer)

