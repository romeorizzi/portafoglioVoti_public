"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:46:32.151849
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
    for node in range(0, vertex_count):
        best_walks[node] = 1000000000000000000

    runtime = edges_count * 3
    itera = 0

    queue.append((0, 0, 0))
    while queue:
        current, apl, apc = queue.pop(0) 

        if valid_parity(apl, lenght_parity) and valid_parity(apc, cost_parity):
            best_walks[current] = min(best_walks[current], apc)

        itera += 1
        if itera >= runtime:
            break

        for _, next_node, cost in edges[current]:
            queue.append((next_node, apl + 1, apc + cost))

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


#input_line = fileinput.input(files ='input.txt')
#vertex_count,edges_count,lenght_parity,cost_parity = map(int,input_line.split())
#for node in range(0, vertex_count):
#        edges[node] = []

#for edge_desc in fileinput.input(files ='input.txt'):
#    tail, head, cost = [int(x) for x in edge_desc.split()]
#    edges[tail].append((tail, head, cost))

best_walks = bfs()

with open("output.txt", "w") as f:
    for i, (node, counter) in enumerate(best_walks.items()):
        if i != 0:
            f.write(" ")
        
        if counter != 1000000000000000000:
            f.write(str(counter))
        else:
            f.write("-1")
