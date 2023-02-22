"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:19:02.050937
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

def dfs(current_node, visited_nodes, APL, APC, target_node):

    # Se siamo a destinazione, se proseguiamo non miglioriamo
    if current_node == target_node and APL != 0:
        if valid_parity(APL, lenght_parity) and valid_parity(APC, cost_parity):
            return APC
        return 100000000000000000

    # non ci sono più strade, non è una soluzione per target_node
    if len(edges[current_node]) == 0:
        return 100000000000000000

    best_path = 100000000000000000
    for edge in edges[current_node]: # (tail, head, cost)
        new_visited_nodes = visited_nodes.copy()
        new_visited_nodes.add(current_node)
        best_path = min(best_path, dfs(edge[1], new_visited_nodes, APL + 1, APC + edge[2], target_node))

    return best_path

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

        # Salviamo il nuovo valore se è il migliore
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
    
    vertex_count, edges_count, lenght_parity, cost_parity = [int(x) for x in lines[0].split()]
    for node in range(0, vertex_count):
        edges[node] = []

    for i, edge_desc in enumerate(lines):
        if i != 0:
            tail, head, cost = [int(x) for x in edge_desc.split()]
            edges[tail].append((tail, head, cost))

best_walks = bfs()

with open("output.txt", "w") as f:
    for node, counter in best_walks.items():
        if counter != 1000000000000000000:
            f.write(str(counter) + " ")
        else:
            f.write("-1" + " ")

