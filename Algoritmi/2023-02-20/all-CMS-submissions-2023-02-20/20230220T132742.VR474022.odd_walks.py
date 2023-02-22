"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 13:27:42.057537
"""


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
        best_walks[node] = 1000000000000000000

    time_since_last_change = 0
    max_time = vertex_count * vertex_count

    visited = set()

    queue = []
    queue.append((0, 0, 0))
    visited.add((0, 0, 0))

    node_visited = set()
    node_visited.add(0)

    while (len(queue) > 0):

        queue = sorted(queue)
        apc, apl, current = queue.pop()

        time_since_last_change += 1
        if time_since_last_change >= max_time + 10:
            break
        
        if valid_parity(apl, lenght_parity) and valid_parity(apc, cost_parity):
            if best_walks[current] > apc:
                #time_since_last_change = 0 # resetta timer
                best_walks[current] = apc

        for _, next_node, cost in edges[current]:
            next_value = (apc + cost, apl + 1, next_node)
            queue.append(next_value)

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
        
        if descr != 1000000000000000000:
            f.write(str(descr))
        else:
            f.write("-1")
