"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 13:49:20.914587
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
import random
PL = 0
PC = 0
adj = []
memo_cost = []
def good_cost(cost):
    if PC==2:
        return True
    if PC==1:
        return cost%2==1
    return cost%2==0

def good_path(steps):
    if PL==2:
        return True
    if PL==1:
        return steps%2==1
    return steps%2==0      

def memo_update(node, steps, cost):
    if good_cost(cost) and good_path(steps):
        memo_cost[node]=min(memo_cost[node], cost)

def search(start, visited, marked, steps, cost):
    memo_update(start, steps, cost)
    arr = adj[start].copy()
    random.shuffle(arr)
    for arch in arr:
        v = arch[0]
        cost_arch = arch[1]
        if (start,v) in visited:
            marked[start][v] +=1
            if(marked[start][v] > 2):
                # Ciclo
                continue
        visited.append((start, v))
        search(v, visited.copy(), marked.copy(), steps+1, cost+cost_arch)

    

if __name__=="__main__":
    N,M,PL,PC = map(int,input().split())
    adj = [[] for _ in range(N)]
    memo_cost = [10**9 for _ in range(N)]
    for i in range(M):
        arch = list(map(int,input().split()))
        adj[arch[0]].append([arch[1], arch[2]])
    # print(adj)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    search(0, [], [[0]*N for _ in range(N)], 0, 0)
    x = False
    while x!=memo_cost:
        search(0, [], [[0]*N for _ in range(N)], 0, 0)
        x=memo_cost.copy()
    
    s = ""
    for i in memo_cost:
        if i == 10**9:
            s+="-1 "
        else:
            s+=f"{i} "
    print(s[:-1])