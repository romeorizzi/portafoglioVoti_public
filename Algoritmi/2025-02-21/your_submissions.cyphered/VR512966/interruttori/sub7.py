#!/usr/bin/env python3
from sys import stderr,stdout, argv
from collections import deque
DEBUG_LEVEL = 0

def solve(n,S,E):
    queue = deque()
    p = [-1] * n
    steps = [-1] * n
    visited = [False] * n

    for k in S:
        steps[k] = 0
        p[k] = k
        queue.append((k, steps[k], p[k]))

    while queue:
        current, step, prev = queue.popleft()
        if visited[current]:
            continue

        visited[current] = True
        for _next in E[current]:
            queue.append((_next, step + 1, current))

        if p[current] == -1:
            p[current] = prev

        if steps[current] == -1:
            steps[current] = step + 1

    return steps, p

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
        n,typ1,typ2 = map(int, input().strip().split())
        S = []
        for _ in range(typ1):
            S.append(int(input()))
        E = []
        for _ in range(typ2):
            E.append(list(map(int, input().strip().split())))
        if DEBUG_LEVEL > 1:
            print(f"# {n=}, {typ1=}, {typ2=}\n# {S=}\n# {E=}\n", file=stderr)

        steps, p = solve(n, S, E)

        print(steps[0])
    
        current = 0
        path = deque()
        while current not in S:
            path.appendleft((p[current], current))
            current = p[current]
        print(current)

        while path:
            tmp = path.popleft()
            print(f"{tmp[0]} {tmp[1]}")

        maxarg = -1
        _max = -1
        for i in range(n):
            if steps[i] > _max:
                maxarg = i
                _max = steps[i]

        print(f"{maxarg} {_max}")

        current = maxarg
        path = deque()
        while current not in S:
            path.appendleft((p[current], current))
            current = p[current]

        print(current)

        while path:
            tmp = path.popleft()
            print(f"{tmp[0]} {tmp[1]}")