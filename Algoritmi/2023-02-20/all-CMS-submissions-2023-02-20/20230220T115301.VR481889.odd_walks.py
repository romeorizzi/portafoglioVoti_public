"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:53:01.107073
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
import math

N,M,PL,PC = map(int,input().split())

graph = [[] for _ in range(M)]

for _ in range(M) :
    a,b,c = map(int,input().split())
    graph[a].append((b,c))

visited = [False] * N
queue = [i for i in reversed(range(N))]
path_cost = [math.inf] * N
path_cost[0] = 0 
path_len = [math.inf] * N
path_len[0] = 0 
sol = [math.inf] * N

#def dfs(u,d, graph) :
#    visited[u] = True
#    for v,c in graph[u] :
#        path_cost[v] = min(d + path_cost[v], d + c)
#        print(f"checking from {u} to {v} with cost {c}")
#        if not visited[v] :
#            #path_cost[v] = min(d + path_cost[v], d + c)
#            print(f"going from {u} to {v} with cost {c}")
#            dfs(v,path_cost[v], graph)


#def dijkstra(graph) :
#    while len(queue) > 0 :
#        i = queue.pop()
#        d = path_cost[i]
#        l = path_len[i]
#        for v,c in graph[i] :
#
#            path_cost[v] = min(path_cost[v], d + c)
#            path_len[v] = min(path_len[v], l + 1 )
#            if (path_cost[v] % 2 == PC % 2 and path_len[v] % 2 == PL % 2) :
#                sol[v] = path_cost[v]
#
#            print(f"checking from {i} to {v} with cost {c}")

def dijkstra(graph) :
    old_sol = sol.copy()
    while True :
        i = queue.pop()
        d = path_cost[i]
        l = path_len[i]
        for v,c in graph[i] :

            path_cost[v] = min(path_cost[v], d + c)
            path_len[v] = min(path_len[v], l + 1 )
            if (PC == 2 and path_len[v] == PL % 2) :
                sol[v] = path_cost[v]
            elif (PL == 2 and path_cost[v] == PC % 2) :
                sol[v] = path_cost[v]
            elif (path_cost[v] % 2 == PC % 2 and path_len[v] % 2 == PL % 2) :
                sol[v] = path_cost[v]

            all_changed = True
            for i in sol :
                if i != -1 :
                    all_changed = False
            if all_changed :
                break

            print(f"checking from {i} to {v} with cost {c}")

timer = 0
def bfs(start, end, graph, path_cost, path_len, visits, timer) :
    timer += 1
    if timer == 20 :
        return
    d = path_cost[start]
    l = path_len[start]
    for v,c in graph[start] :

        #print(f"checking from {start} to {v} with cost {c}")
        visits[v] += 1

        path_cost[v] = d + c
        path_len[v] = l + 1

        if (PC == 2 and path_len[v] == PL % 2) :
            sol[v] = min(path_cost[v], sol[v])
        elif (PL == 2 and path_cost[v] == PC % 2) :
            sol[v] = min(path_cost[v], sol[v])
        if (path_cost[v] % 2 == PC % 2 and path_len[v] % 2 == PL % 2) :
            sol[v] = min(path_cost[v], sol[v])

        if v == end:
            #print("end reached")
            continue

        #if sol[v] != math.inf :
        #        if (path_cost[v] % 2 == PC % 2 and path_len[v] % 2 == PL % 2) :
        #            if sol[v] != path_cost[v] :
        #                print("cant get new solutions")
        #                continue

        bfs(v, end, graph, path_cost, path_len, visits,timer)


        #print("end")


#bfs(0,0, graph, path_cost, path_len)


output = []
for i in range(N) :
    #i = 1
    
    path_cost = [math.inf] * N
    path_cost[0] = 0 
    path_len = [math.inf] * N
    path_len[0] = 0 
    loop = [False] * N
    visits = [0] * N
    sol = [math.inf] * N
    bfs(0,i, graph, path_cost, path_len,visits, 0)
    if not sol[i] == math.inf :
        output.append(sol[i])
    else :
        output.append(-1)

print(output)
