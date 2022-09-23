"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esamebridges_and_cutnodes
* score: 32.0
* date:  2022-07-26 12:18:36.939434
"""
import sys
sys.setrecursionlimit(10**9)

t, n, m = map(int, input().strip().split())

bridges = [False] * m
cutnodes = [False] * n

edges = {}
arr = [ [] for v in range(n)]

for i in range(m):
    u,v = map(int, input().strip().split())
    arr[u].append(v)
    arr[v].append(u)
    edges[(u, v)] = i
    edges[(v, u)] = i

    
    


time = 1
seq = [None] * n
small = [None] * n

def solve(nodeIndex, node, dad):
    global time, seq, small, bridges, cutnodes, edges
    assert nodeIndex <= n

    small[node] = seq[node] = time
    time += 1
    num_children_v = 0
    for i in arr[node]:
        if seq[i] == None:
            num_children_v += 1
            solve(nodeIndex + 1, i, node)
            small[node] = min(small[node], small[i])
            if small[i] > seq[node]:
                bridges[edges[(node, i)]] = True
            if small[i] >= seq[i] and node != 0:
                cutnodes[node] = True
        elif i != dad:
            small[node] = min(small[node], seq[i])
    assert small[node] <= seq[node]
    if node == 0:
        if num_children_v > 1:
            cutnodes[node] = True

solve(0, 0, 0)

if t == 1:
    for index in range(m):
       print(1) if bridges[index] else print(0)

if t == 2:
    for index in range(n):
       print(1) if cutnodes[index] else print(0)