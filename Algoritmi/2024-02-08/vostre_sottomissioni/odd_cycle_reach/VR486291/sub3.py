import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
sys.setrecursionlimit(10**6)

def is_odd_cycle(graph, start, color): #funzione per verificare la presenza di un ciclo dispari utilizzando un approccio DFS
    
    stack = [(start, -1, 0)] # Inizializzo stack con il nodo di partenza, il nodo parent e la profondità
    
    while stack:
        
        node, parent, depth = stack.pop()
        
        if color[node] != -1:
            #Se il nodo è gia visitato e la differenza di profondità è dispari, abbiamo trovato un ciclo dispari
            if (depth - color[node]) % 2 == 1: 
                return True
            continue
        color[node] = depth # Colora il node con la sua profondità

        for neighbor in graph[node]:
            if neighbor == parent: continue
            stack.append((neighbor, node, depth + 1))
    
    return False

# Funzione principale per trovare tutti i nodi che possono raggiungere un ciclo dispari in un grafo
def find_odd_cycle_nodes(graph, n):
    
    color = [-1] * n 
    
    for node in range(n):
        if color[node] == -1: #Se il nodo non è stato ancora visitato
            #Eseguo la DFS per trovare un ciclo dispari
            if is_odd_cycle(graph, node, color):
            #Se viene trovato, tutti i nodi del grafo possono raggiungerlo
                return [i for i in range(n)] #Restituisco tutti i nodi del grafo
    
    return [] #vuoto se non ci sono

T = int(input().strip())

for _ in range(T):
    
    n, m = map(int, input().split())
    
    graph = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v = map(int, input().strip().split())
        graph[u].append(v)
        graph[v].append(u)

    odd_cycle_nodes = find_odd_cycle_nodes(graph, n)
    
    print(len(odd_cycle_nodes))
    
    if odd_cycle_nodes:
        print(' '.join(map(str, odd_cycle_nodes)))