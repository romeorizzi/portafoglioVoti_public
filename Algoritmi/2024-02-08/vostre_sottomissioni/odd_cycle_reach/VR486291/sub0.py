import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29, -1))
sys.setrecursionlimit(10**6)

def is_odd_cycle(graph, start, color):
    stack = [(start, -1, 0)]
    while stack:
        node, parent, depth = stack.pop()
        if color[node] != -1:
            if (depth - color[node]) % 2 == 1:
                return True
            continue
        color[node] = depth

        for neighbor in graph[node]:
            if neighbor == parent: continue
            stack.append((neighbor, node, depth + 1))
    return False

def find_odd_cycle_nodes(graph, n):
    color = [-1] * n 
    for node in range(n):
        if color[node] == -1:
            if is_odd_cycle(graph, node, color):
                return [i for i in range(n)]
    return []

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