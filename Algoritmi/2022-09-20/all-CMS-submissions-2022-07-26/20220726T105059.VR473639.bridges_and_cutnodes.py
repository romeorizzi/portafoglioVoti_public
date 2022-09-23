"""
* user:  VR473639
* fname: ANDREA
* lname: CINELLI
* task:  esamebridges_and_cutnodes
* score: 32.0
* date:  2022-07-26 10:50:59.015725
"""
import sys
sys.setrecursionlimit(10**9)

t, n, m = map(int, input().strip().split())


n_comp = [0] + [1] * (n - 1)
brid = [False] * m

edg = {}

# Per ogni vertice salvo a quali vertici è connesso
v_conn = [ [] for v in range(n)]
for i in range(m):
    u,v = map(int, input().strip().split())
    v_conn[u].append(v)
    v_conn[v].append(u)
    edg[(u, v)] = i
    edg[(v, u)] = i


time = 1
l = [None] * n
op = [None] * n

def dfs(h, v, dad):
    global time, op, l, brid, n_comp
    assert h <= n

    l[v] = op[v] = time
    time += 1
    
    n_ch_v = 0
    for z in v_conn[v]:
        if op[z] == None:
            n_ch_v += 1
            dfs(h + 1, z, v)
            l[v] = min(l[v], l[z])
            if l[z] > op[v]:
                brid[edg[(v, z)]] = True
            if l[z] >= op[v]:
                n_comp[v] += 1
        elif z != dad:
            l[v] = min(l[v], op[z])
    assert l[v] <= op[v]
    if v == 0:
        assert n_comp[v] == n_ch_v

dfs(0, 0, 0)

if t == 1:
    for i in range(m):
        if brid[i]:
            print(1)
        else:
            print(0)
