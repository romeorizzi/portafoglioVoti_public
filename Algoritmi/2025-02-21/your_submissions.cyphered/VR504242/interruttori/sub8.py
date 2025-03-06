#!/usr/bin/env python3
from sys import stderr,stdout, argv
from collections import deque

DEBUG_LEVEL = 0

def solve(n,S,E):
    grafo = [[] for _ in range(n)]
    dist = [-1] * n 

    Q = deque()

    for x in S:
        dist[x] = 1
        Q.append((x, []))

    for x,y in E:
        grafo[x].append[y]
        grafo[y].append[x]

    min_cost = -1
    min_solution = []
    while Q:
        v, path = Q.popleft()
        if v == 0:
            min_cost = len(path)
            min_solution = path 
            break
        for i in grafo[v]:
            if dist[i] == -1:
                dist[i] = dist[v] + 1
                Q.append((i, path + [i]))

    max_cost = max(dist)
    max_index = dist.index(max_cost)

    Q.clear()
    dist = [-1] * n 
    Q.append((max_index, []))
    dist[max_index] = 1
    max_solution = []
    while Q:
        v, path = Q.popleft()
        if v == 0:
            max_solution = path
            break 
        for i in grafo[v]:
            if dist[i] == -1:
                dist[i] = dist[v] + 1
                Q.append((i, path + [i]))

    return min_cost, min_solution, max_index, max_cost, max_solution

def print_sol(fout, switches):
    for sw in switches:
        if type(sw) == list:
            print(f"{sw[0]} {sw[1]}", file=fout)
        else:
            print(sw, file=fout)


if __name__ == "__main__":
    if len(argv) == 2:
        DEBUG_LEVEL = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if DEBUG_LEVEL > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n,typ1, typ2 = map(int, input().strip().split())
        S = []
        for _ in range(typ1):
            S.append(int(input()))
        E = []
        for _ in range(typ2):
            E.append(list(map(int, input().strip().split())))
        if DEBUG_LEVEL > 1:
            print(f"# {n=}, {typ1=}, {typ2=}\n# {S=}\n# {E=}\n", file=stderr)
        cost_0, switches_for_0, v_max, cost_v_max, switches_for_v_max = solve(n,S,E)
        
        fouts = [stdout]
        if DEBUG_LEVEL > 0:
            fouts.append(stderr)
        for fout in fouts:
            print(cost_0, file=fout)
            print_sol(fout, switches_for_0)
            print(f"{v_max} {cost_v_max}", file=fout)
            print_sol(fout, switches_for_v_max)
