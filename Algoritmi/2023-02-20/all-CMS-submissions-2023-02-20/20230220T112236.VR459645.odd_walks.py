"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_odd_walks
* score: 20.0
* date:  2023-02-20 11:22:36.887775
"""
#!/usr/bin/python
import heapq


# Leggi il file di input
with open('input.txt', 'r') as f:
    N, M, _, _ = map(int, f.readline().split())
    graph = [[] for _ in range(N)]
    for i in range(M):
        u, v, w = map(int, f.readline().split())
        graph[u].append((v, w))

# Inizializza il vettore dei costi minimi
cost = [-1]*N
cost[0] = 0

# Usa l'algoritmo di Dijkstra per trovare il cammino di costo minimo da 0 a tutti gli altri nodi
pq = [(0, 0)]
while pq:
    c, u = heapq.heappop(pq)
    if c > cost[u]:
        continue
    for v, w in graph[u]:
        if cost[u] == -1:
            cost[v] = -1
            continue
        if cost[v] == -1 or cost[u] + w < cost[v]:
            cost[v] = cost[u] + w
            heapq.heappush(pq, (cost[v], v))

# Scrivi il file di output
with open('output.txt', 'w') as f:
    for c in cost:
        f.write(str(c) + ' ')
