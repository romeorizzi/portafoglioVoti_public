#!/usr/bin/env python3
from sys import stderr,stdout, argv

DEBUG_LEVEL = 0

if __name__ == "__main__":
    if len(argv) == 2:
        DEBUG_LEVEL = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if DEBUG_LEVEL > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n,m = map(int, input().strip().split())
        V = list(map(int, input().strip().split()))
        G = list(map(int, input().strip().split()))
        if DEBUG_LEVEL > 1:
            print(f"# {n=}, {m=}\n# {V=}\n# {G=}\n", file=stderr)


        opt_val = 0
        optS = ["1"] * m; optT = ["1"] * n
        num_opt_sols = 69
        num_opt_sets = 666
        
        V_cost = [0] * n
        j = 0
        for i in range(n):
            if (j == len(G)):
                j = 0
            while j < m:
                if(V[i] < G[j]):
                    # entrano in coppia
                    V_cost[i] = 2
                    j = j + 1 
                    break
                V_cost[i] = 1 
                j = j + 1      
        
        for m in range(len(V_cost)):
            opt_val += V_cost[m]

        fouts = [stdout]
        if DEBUG_LEVEL > 0:
            fouts.append(stderr)
        for fout in fouts:
            print(opt_val, file=fout)
            print(" ".join(optT), file=fout)
            print(" ".join(optS), file=fout)
            print(num_opt_sols, file=fout)
            print(num_opt_sets, file=fout)
