"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 15.0
* date:  2023-02-20 13:06:47.755567
"""


class Node:
    def __init__(self):
        self.value  = 1000000000000000000
        self.hits = 0

    def cycles(self):
        return max(0, self.hits - 1)

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
        best_walks[node] = Node()

    time_since_last_change = 0
    max_time = vertex_count * edges_count

    visited = set()

    queue = []
    queue.append((0, 0, 0))
    visited.add((0, 0, 0))

    node_visited = set()
    node_visited.add(0)

    while queue:
        current, apl, apc = queue.pop(0)
        best_walks[current].hits += 1

        if valid_parity(apl, lenght_parity) and valid_parity(apc, cost_parity):
            if best_walks[current].value > apc:
                #time_since_last_change = 0 # resetta timer
                best_walks[current].value = apc

        time_since_last_change += 1
        if time_since_last_change >= max_time + 10:
            break
        
        for _, next_node, cost in edges[current]:
            next_value = (next_node, apl + 1, apc + cost)
            if not next_value in visited:
                queue.append((next_node, apl + 1, apc + cost))
                visited.add(next_value)

    return best_walks


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
    for i, (node, descr) in enumerate(best_walks.items()):
        if i != 0:
            f.write(" ")
        
        if descr.value != 1000000000000000000:
            f.write(str(descr.value))
        else:
            f.write("-1")
