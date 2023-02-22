"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:15:30.457950
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
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
    for arch in adj[start]:
        v = arch[0]
        cost_arch = arch[1]
        if (start,v) in visited:
            if (start,v) in marked:
                #print(f"node:{start} {v} {cost}")
                continue
            marked.append((start,v))
        visited.append((start, v))
        search(v, visited.copy(), marked, steps+1, cost+cost_arch)
# Visited è sbagliato

if __name__=="__main__":
    N,M,PL,PC = map(int,input().split())
    adj = [[] for _ in range(N)]
    memo_cost = [10**9 for _ in range(N)]
    for i in range(M):
        arch = list(map(int,input().split()))
        adj[arch[0]].append([arch[1], arch[2]])
    # print(adj)
    search(0, [], [], 0, 0)
    s = ""
    for i in memo_cost:
        if i == 10**9:
            s+="-1 "
        else:
            s+=f"{i} "
    print(s[:-1])