"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esamebridges_and_cutnodes
* score: 65.0
* date:  2022-07-26 12:29:33.334902
"""
import sys
sys.setrecursionlimit(10**9)

t, n, m = map(int, input().strip().split())

bridges = [False] * m
cutnodes = [0] + [1] * (n - 1)

edges = {}
nei = [ [] for v in range(n)]
for i in range(m):
    u,v = map(int, input().strip().split())
    nei[u].append(v)
    nei[v].append(u)
    edges[(u, v)] = i
    edges[(v, u)] = i


time = 1
seq = [None] * n
small = [None] * n

def solve(h, v, dad):
    global time, seq, small, bridges, cutnodes
    assert h <= n

    small[v] = seq[v] = time
    time += 1
    num_children_v = 0
    for z in nei[v]:
        if seq[z] == None:
            num_children_v += 1
            solve(h + 1, z, v)
            small[v] = min(small[v], small[z])
            if small[z] > seq[v]:
                bridges[edges[(v, z)]] = True
            if small[z] >= seq[v]:
                cutnodes[v] += 1
        elif z != dad:
            small[v] = min(small[v], seq[z])
    assert small[v] <= seq[v]
    if v == 0:
       assert cutnodes[v] == num_children_v

solve(0, 0, 0)

if t == 1:
    for e_index in range(m):
       print(1) if bridges[e_index] else print(0)
if t == 2:
    for v in range(n):
       print(1) if cutnodes[v] > 1 else print(0)