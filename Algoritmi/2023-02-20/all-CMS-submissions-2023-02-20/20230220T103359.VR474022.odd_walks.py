"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:33:59.249954
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

visited = [] # List for visited nodes.
queue = []     #Initialize a queue

def bfs(): #function for BFS

    best_walks = { }

    runtime = edges_count * 3
    itera = 0

    queue.append((0, 0, 0))
    while queue:
        current, apl, apc = queue.pop(0) 

        # Aggiungiamo nodo se non esiste
        if not current in best_walks:
             best_walks[current] = 1000000000000000000

        if valid_parity(apl, lenght_parity) and valid_parity(apc, cost_parity):
            best_walks[current] = min(best_walks[current], apc)

        itera += 1
        if itera >= runtime:
            break

        for _, next_node, cost in edges[current]:
            queue.append((next_node, apl + 1, apc + cost))

    return best_walks

input_line = input()
vertex_count,edges_count,lenght_parity,cost_parity = map(int,input_line.split())
for node in range(0, vertex_count):
        edges[node] = []

for edge_desc in input():
    tail, head, cost = [int(x) for x in edge_desc.split()]
    edges[tail].append((tail, head, cost))

best_walks = bfs()

for i, node, counter in enumerate(best_walks.items()):

    sys.stdout.write('.')

    if i != 0:
        sys.stdout.write(" ")
    if counter != 1000000000000000000:
        sys.stdout.write(str(counter))
    else:
        sys.stdout.write(str("-1"))
sys.stdout.write("\n")
