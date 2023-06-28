"""
* user:  VR474565
* fname: MATTIA
* lname: SANTI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 13:41:47.581806
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N,M,PL,PC = map(int,input().split())

def minimumCostPath(u, d, visited, graph):
	if (u == d):
		return 0
	visited[u] = 1
	ans = 100000000

	for i in range(N):
		if (graph[u][i] != 100000000 and not visited[i]):
			curr = minimumCostPath(i, d, visited, graph)
			if (curr < 100000000):
				ans = min(ans, graph[u][i] + curr)
	visited[u] = 0
	return ans

walk_list = [[] for _ in range(N)]

def depthFirst(graph, currentVertex, visited):
    visited.append(currentVertex)
    for vertex in graph[currentVertex]:
        if vertex not in visited:
            depthFirst(graph, vertex, visited.copy())
    walk_list[currentVertex].append(visited)

edge_costs = [[(100000000) for _ in range(N)] for _ in range(N)]
neig = [[] for _ in range(N)]
visited = [0 for _ in range(N)]

for _ in range(M):
	tail, head, cost = map(int,input().strip().split())
	edge_costs[tail][head] = cost
	neig[tail].append(head)

#Soluzioni partendo dal presupposto che non ci siano soluzioni
sol = [-1 for _ in range(N)]

#Ottengo tutti i walk
depthFirst(neig, 0, [])

for i in range(N):
	if(PL == 0 and PC == 0):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 1):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 1):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
		
	if(PL == 0 and PC == 1):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 1):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 0):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 0 and PC == 2):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 1):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 1 and PC == 0):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 0):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 1):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 1 and PC == 1):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 0):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 0):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 1 and PC == 2):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			if(len(walk_list[i][j]) % 2 == 0):
				continue
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 2 and PC == 0):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 1):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 2 and PC == 1):
		cost_min = 100000000
		#Per ogni walk
		for j in range(len(walk_list[i])):
			cost = 0
			#Per ogni edge
			for k in range(len(walk_list[i][j])):
				cost += edge_costs[k][k+1]
			if(cost%2 == 0):
				continue
			if(cost < cost_min):
				cost_min = cost
		sol[i] = cost_min
	if(PL == 2 and PC == 2):
		sol[i] = minimumCostPath(0, i, visited, edge_costs);
	
	
print(sol)
