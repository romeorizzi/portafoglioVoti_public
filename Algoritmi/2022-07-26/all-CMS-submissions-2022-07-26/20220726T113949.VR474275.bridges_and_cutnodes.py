"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esamebridges_and_cutnodes
* score: 32.0
* date:  2022-07-26 11:39:49.296359
"""
import sys
sys.setrecursionlimit(10**9)

t, n, m = map(int, input().strip().split())

bridges = [False] * m

edges = {}
arr = [ [] for v in range(n)]

for i in range(m):
    u,v = map(int, input().strip().split())

    edges[(u, v)] = i
    edges[(v, u)] = i

    arr[u].append(v)
    arr[v].append(u)
    


time = 1
seq = [None] * n
small = [None] * n

def solve(nodeIndex, node, dad):
    global time, seq, small, bridges
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
        elif i != dad:
            small[node] = min(small[node], seq[i])
    assert small[node] <= seq[node]



solve(0, 0, 0)

if t == 1:
    for index in range(m):
       print(1) if bridges[index] else print(0)