#!/usr/env/bin python3

import sys, os


import resource
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

def dispari(el):
    somma = 0
    for e in el:
        somma = somma + 1
    
    if(somma % 2 == 0):
        return False
    
    return True


def dfs(node, graph, visited):
    visited[node] = True
    component = [node]

    for neighbor in graph[node]:
        if not visited[neighbor]:
            component.extend(dfs(neighbor, graph, visited))

    return component


def connected_components(graph):
    n = len(graph)
    visited = [False] * n

    components = []

    for node in range(n):
        if not visited[node]:
            component = dfs(node, graph, visited)
            components.append(component)

    return components


T = int(input())

for _ in range(T):
    n, m = map(int , input().split())
    graph = [[] for _ in range(n)]

    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)


    components = connected_components(graph)

    #print(len(components))

    #for el in components:
    #    print(el)

    quanti = 0

    for el in components:
        isDispari = dispari(el)

        if(isDispari):
            #Li conto
            for e in el:
                quanti = quanti + 1

    print(quanti)

    res = []

    for el in components:
        isDispari = dispari(el)

        if(isDispari):
            for e in el:
                res.append(e)

    
    result = ""

    for el in res:
        result = result + str(el) + " "

    print(result)