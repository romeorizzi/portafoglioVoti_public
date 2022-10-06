"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 12:27:25.426981
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
opent = [None] * n
low = [None] * n

def solve(nodeIndex, node, dad):
    global time, opent, low, bridges, cutnodes
    assert nodeIndex <= n

    low[node] = opent[node] = time
    time += 1
    num_children_v = 0
    for i in nei[node]:
       if opent[i] == None:
            num_children_v += 1
            solve(nodeIndex + 1, i, node)
            low[node] = min(low[node], low[i])
            if low[i] > opent[node]:
                bridges[edges[(node, i)]] = True
            if low[i] >= opent[node]:
                cutnodes[node] += 1
        elif i != dad:
            low[node] = min(low[node], opent[i])
    assert low[node] <= opent[node]
    if node == 0:
       assert cutnodes[node] == num_children_v

solve(0, 0, 0)

if t == 1:
    for e_index in range(m):
       print(1) if bridges[e_index] else print(0)
if t == 2:
    for v in range(n):
       print(1) if cutnodes[v] > 1 else print(0)