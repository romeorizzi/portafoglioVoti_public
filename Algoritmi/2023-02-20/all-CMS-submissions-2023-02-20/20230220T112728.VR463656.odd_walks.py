"""
* user:  VR463656
* fname: GIOVANNI
* lname: DANIELI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:27:28.651514
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N,M,PL,PC = map(int,input().split())
COSTI = [[0 for _ in range(N)] for _ in range(M)]
figli = [[] for _ in range(M)]

for _ in range(M):
    t, h, c = map(int, input().split())
    figli[t].append(h)
    COSTI[t][h] = c



def dfs(node:int, goal:int, l: int, c: int, visitati: list):
    if node == goal and (PL==2 or l % 2 == PL) and (PC==2 or c % 2 == PC):
        return c
    result = []
    visitati[node] += 1
    for figlio in figli[node]:
        temp = None
        if l == 0:
            visitati = [0 for _ in range(N)]
            temp = dfs(figlio, goal, l + 1, c + COSTI[node][figlio], visitati)
        else:
            if visitati[figlio] <= 2:
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

print(answer)

