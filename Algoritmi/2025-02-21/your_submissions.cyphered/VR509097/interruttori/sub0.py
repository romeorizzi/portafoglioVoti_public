#!/usr/bin/env python3
from sys import stderr,stdout, argv

DEBUG_LEVEL = 0

def solve(n,S,E):
    cost_0 = 4
    switches_for_0 = [2, [2,7], [7,4], [4,0] ]
    v_max = 17
    cost_v_max = 1
    switches_for_v_max = [17]

    # Calcolo cost_0 e switches_for_0

    # Identifico se alla lampadina 0 è associato un interruttore privato
    if (0 in S):
        cost_0 = 1
        switches_for_0 = []
        for edge in E:
            if edge[0] == 0:
                switches_for_0.append(edge[1])
                break

    return cost_0, switches_for_0, v_max, cost_v_max, switches_for_v_max

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
