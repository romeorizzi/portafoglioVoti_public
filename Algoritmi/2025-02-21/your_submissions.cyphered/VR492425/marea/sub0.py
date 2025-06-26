#!/usr/bin/env python3
import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

from sys import stdin, stderr, stdout, argv
#sys.stdin = open("input.txt", "r")
#sys.stdout = open("output.txt", "w")


def solve(n, H, w):
    A = [i for i in H]
    Q = 0

    # Riempimento da sinistra
    d = False
    i = 0
    while not d and i < len(A):
        if A[i] < w:
            A[i] = w
        else:
            d = True
        i += 1

    # Riempimento da destra
    d = False
    j = len(A) -1
    while not d and j > 0 and j > i:
        if A[j] < w:
            A[j] = w
        else:
            d = True
        j -= 1


    # Svuotamento da sinistra
    d = False
    m = w
    i = 0
    while not d and i < len(A):
        if A[i] > H[i]:
            A[i] = max(H[i], m)
            m = H[i]
        else:
            d = True
        i += 1


    # Svuotamento da DESTRA
    d = False
    m = w
    j = len(A) -1
    while not d and j > 0 and j > i:
        if A[j] > H[j]:
            A[j] = max(H[j], m)
            m = H[j]
        else:
            d = True
        j -= 1


    A[0] = H[0] 
    A[-1] = H[-1]

    #print(A, H)
    Q = sum(A) - sum(H)

    return Q, A
     
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n, w = list(map(int, input().strip().split()))
        H = list(map(int, input().strip().split())); assert(len(H)==n); assert(all([_ >= 0 for _ in H]))
        if debug_level > 1:
            print(f"# {n=}\n# {H=}", file=stderr)
        Q,A = solve(n,H, w)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))
