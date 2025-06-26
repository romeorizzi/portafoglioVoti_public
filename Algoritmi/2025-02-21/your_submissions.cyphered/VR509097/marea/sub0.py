#!/usr/bin/env python3
from sys import stderr, stdout, argv

def solve(n,w,H):
    #print("-----------------------")
    A = H[:]
    Q = 0

    # Per ogni livello, simulo un'espansione in ambo le direzioni
    for l in range (0, w):
        lsx = None
        ldx = None

        # cerco i limiti per questo livello
        for i in range (1, n-1):
            # limite sx
            if (lsx is None and H[i] > l):
                lsx = i
            # limite dx
            if (ldx is None and H[n - i - 1] > l):
                ldx = n - i - 1
            # break quando ho trovato entrambi
            if (lsx is not None and ldx is not None):
                break

        if (lsx is None):
            lsx = 0

        if (ldx is None):
            ldx = n - 1
        # riempio i buchi con acqua
        # print(f"SX Liv {l} ciclo tra 1 < b < {lsx}")
        for i in range(1, lsx):
            qta = A[i - 1] - A[i]
            if qta > 0:
                #print(f"\triempio cella {i} di {qta} acqua")
                A[i] += qta
                Q += qta

        #print(f"DX Liv {l} ciclo tra {ldx} < b < {n - 2}")
        for i in range(n - 2, ldx, -1):
            qta = A[i + 1] - A[i]
            if qta > 0:
                #print(f"\triempio cella {i} di {qta} acqua")
                A[i] += qta
                Q += qta

    return Q, A    
              
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n, w = map(int, input().strip().split())
        H = list(map(int, input().strip().split())); assert(len(H)==n); assert(all([_ >= 0 for _ in H]))
        if debug_level > 1:
            print(f"# {n=}\n# {H=}", file=stderr)
        Q,A = solve(n,w,H)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))
