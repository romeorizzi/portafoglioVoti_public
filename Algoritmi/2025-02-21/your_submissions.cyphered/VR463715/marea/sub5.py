#!/usr/bin/env python3
from sys import stderr, stdout, argv

def solve(n, H):
    max_left = [0] * n
    max_right = [0] * n
    A = [0] * n
    Q = 0
    
    # Calcoliamo max_left (massima altezza a sinistra)
    max_left[0] = H[0]
    for i in range(1, n):
        max_left[i] = max(max_left[i-1], H[i])

    # Calcoliamo max_right (massima altezza a destra)
    max_right[n-1] = H[n-1]
    for i in range(n-2, -1, -1):
        max_right[i] = max(max_right[i+1], H[i])

    # Calcoliamo l'acqua intrappolata
    for i in range(n):
        A[i] = min(max_left[i], max_right[i])  # Minimo tra le due altezze
        if A[i] > H[i]:
            Q += A[i] - H[i]  
    return Q, A
              
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n, w = map(int, input().split())  # leggi n e w
        assert(1 <= n <= 10**6)
        H = list(map(int, input().strip().split()))  # leggi le altezze
        assert(len(H) == n)
        assert(all([_ >= 0 for _ in H]))
        if debug_level > 1:
            print(f"# {n=}, {w=}, {H=}", file=stderr)
        Q, A = solve(n, H, w)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))
