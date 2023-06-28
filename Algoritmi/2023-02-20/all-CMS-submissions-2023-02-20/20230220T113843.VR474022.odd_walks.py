"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:38:43.970962
"""


import sys

# (tail, head, cost)
edges = dict()
vertices = []

vertex_count = 0
edges_count = 0
lenght_parity = 2
cost_parity = 2

def valid_parity(value, parity):
    if parity == 0:
        return value % 2 == 0
    if parity == 1:
        return value % 2 != 0
    if parity == 2:
        return True
    return False

def bfs(): #function for BFS

    best_walks = { }
    for node in range(0, vertex_count):
        best_walks[node] = {
            apl: 1000000000000000000,
            visits: 0
        }

    time_since_last_change = 0
    max_time = vertex_count * 100

    visited = set()

    queue = []
    queue.append((0, 0, 0))
    visited.add((0, 0, 0))

    while queue:
        current, apl, apc = queue.pop(0)

        # Se un nodo viene visitato più di e
        best_walks[current].visits += 1
        if best_walks[current].visits >= vertex_count:
            break

        if valid_parity(apl, lenght_parity) and valid_parity(apc, cost_parity):
            if best_walks[current] > apc:
                #time_since_last_change = 0 # resetta timer
                best_walks[current] = apc

        #time_since_last_change += 1
        #if time_since_last_change >= max_time:
            #break
        
        for _, next_node, cost in edges[current]:
            next_value = (next_node, apl + 1, apc + cost)
            if not next_value in visited:
                queue.append((next_node, apl + 1, apc + cost))

    return best_walks


def dijkstra(startingNode):

	visited = set()
	parentsMap = {}
	pq = []
	nodeCosts = defaultdict(lambda: float('inf'))

	nodeCosts[startingNode] = 0
	heap.heappush(pq, (0, startingNode))
 
	while pq:
		# go greedily by always extending the shorter cost nodes first
		_, node = heap.heappop(pq)
		visited.add(node)
 
		for adjNode, weight in egdes[node].items():
			if adjNode in visited:	continue
				
			newCost = nodeCosts[node] + weight
			if nodeCosts[adjNode] > newCost:
				parentsMap[adjNode] = node
				nodeCosts[adjNode] = newCost
				heap.heappush(pq, (newCost, adjNode))
        
	return parentsMap, nodeCosts


with open("input.txt") as f:
    lines = [line for line in f]
    vertex_count,edges_count,lenght_parity,cost_parity = map(int, lines[0].split())
    for node in range(0, vertex_count):
        edges[node] = []

    for i, edge_desc in enumerate(lines):
        if i != 0:
            tail, head, cost = [int(x) for x in edge_desc.split()]
            edges[tail].append((tail, head, cost))

best_walks = bfs()

with open("output.txt", "w") as f:
    for i, (node, counter) in enumerate(best_walks.items()):
        if i != 0:
            f.write(" ")
        
        if counter != 1000000000000000000:
            f.write(str(counter))
        else:
            f.write("-1")
