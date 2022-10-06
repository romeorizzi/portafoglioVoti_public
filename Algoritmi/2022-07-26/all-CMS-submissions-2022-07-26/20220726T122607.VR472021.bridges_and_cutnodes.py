"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esamebridges_and_cutnodes
* score: 65.0
* date:  2022-07-26 12:26:07.431256
"""

t,n,m = tuple(map(int,input().split()))

E = dict()
archi_nodi = [] 

for v in range(n):
    archi_nodi.append([])


for i in range(m):
    v1,v2 = tuple(map(int,input().split()))
    archi_nodi[v1].append(v2)
    archi_nodi[v2].append(v1)
    E[(v2, v1)] = i
    E[(v1, v2)] = i

tt = 1
discover = [0]*n
low = [0]*n

bridge = [0]*m
cutnode = [0] + [1]*(n-1)

def dfs(dep, v, p):
    global tt, discover, low,cutnode, bridge
    if dep > n:
        return 

    
    low[v] = tt
    discover[v] = tt
    tt +=1
    c_visit = 0

    for near_idx in archi_nodi[v]:

        if discover[near_idx] == 0:
            c_visit += 1
            dfs(dep + 1, near_idx, v)

            if low[v] > low[near_idx]:
                low[v] = low[near_idx]

            if low[near_idx] >= discover[v]:
                if low[near_idx] != discover[v]:
                    bridge[E[(v, near_idx)]] = 1
                cutnode[v] += 1

        elif near_idx != p:
            low[v] = min(low[v], discover[near_idx])

    if low[v] > discover[v]:
        return 

    if v == 0:
        if cutnode[v] != c_visit:
            return


dfs(0,0,-1)

if t == 1:
    for e in range(m):
        print(bridge[e])
elif t == 2:
    for v in range(n):
        if cutnode[v] > 1:
            print(1)
        else:
            print(0)





