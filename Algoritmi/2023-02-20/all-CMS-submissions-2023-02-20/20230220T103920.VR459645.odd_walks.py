"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:39:20.167811
"""
#!/usr/bin/python
import heapq

# Lettura dell'input dal file
with open('input.txt', 'r') as f:
    N, M, _, _ = map(int, f.readline().split())
    graph = [[] for _ in range(N)]
    for _ in range(M):
        u, v, c = map(int, f.readline().split())
        graph[u].append((v, c))

# Funzione che calcola i cammini minimi da un nodo sorgente usando l'algoritmo di Dijkstra
def dijkstra(graph, start):
    pq = [(0, start)]
    dist = [float('inf') for _ in range(len(graph))]
    dist[start] = 0
    while pq:
        d, u = heapq.heappop(pq)
        if d > dist[u]:
            continue
        for v, c in graph[u]:
            if dist[u] + c < dist[v]:
                dist[v] = dist[u] + c
                heapq.heappush(pq, (dist[v], v))
    return dist

# Calcolo dei cammini minimi da ogni nodo al nodo 0
results = [str(d) for d in dijkstra(graph, 0)]

# Scrittura dell'output sul file
with open('output.txt', 'w') as f:
    f.write(' '.join(results))



