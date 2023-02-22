"""
* user:  VR459645
* fname: FRANCESCA
* lname: ANNIBALETTI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 10:07:53.887216
"""
#!/usr/bin/python

def read_input_file(input_file):
    with open(input_file, 'r') as f:
        n, m, pl, pc = map(int, f.readline().split())
        graph = [[] for _ in range(n)]
        for _ in range(m):
            u, v, c = map(int, f.readline().split())
            graph[u].append((v, c))
        return n, m, pl, pc, graph

def write_output_file(output_file, result):
    with open(output_file, 'w') as f:
        f.write(' '.join(str(x) for x in result))

def odd_walks(input_file, output_file):
    n, m, pl, pc, graph = read_input_file(input_file)
    INF = float('inf')
    result = [-1] * n
    for parity_cost in range(pc, 2, 2):
        for parity_len in range(pl, 2, 2):
            dist = [[INF for _ in range(2)] for _ in range(n)]
            dist[0][0] = 0
            queue = [(0, 0)]
            while queue:
                u, parity = queue.pop(0)
                for v, c in graph[u]:
                    new_dist = dist[u][parity] + c
                    new_parity = parity ^ 1
                    if new_dist < dist[v][new_parity]:
                        dist[v][new_parity] = new_dist
                        queue.append((v, new_parity))
            for i in range(n):
                if dist[i][parity_len % 2] != INF and (result[i] == -1 or dist[i][parity_len % 2] < result[i]):
                    if parity_cost == 2 or dist[i][parity_len % 2] % 2 == parity_cost:
                        result[i] = dist[i][parity_len % 2]
    write_output_file(output_file, result)

odd_walks("input.txt", "output.txt")



