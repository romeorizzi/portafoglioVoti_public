#!/usr/bin/env python3
from sys import stderr, stdout, argv

def solve(n, w, H):
    # TODO: write here your solution!
    # what follows will be just good enough to respect the intended communication protocol with the server
    A = [13] * n
    Q = 0
    mfl = [H[0]] * n
    mfr = [H[len(H) - 1]] * n
    for i in range(1, len(H), 1):
        mfl[i] = max(mfl[i - 1], H[i])
        mfr[len(H) - 1 - i] = max(mfr[len(H) - i], H[len(H) - 1 - i])
    
    for i in range(len(H)):
        temp = min(mfl[i], mfr[i])
        if(temp >= w):
            A[i] = H[i]
        else:
            A[i] = temp
    
    for i in range(len(H)):
        Q += A[i] - H[i]
        
    return Q,A    
              
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        L = list(map(int, input().strip().split()))
        n = L[0]
        w = L[1]
        H = list(map(int, input().strip().split()))
        if debug_level > 1:
            print(f"# {n=}\n# {H=}", file=stderr)
        Q,A = solve(n,w,H)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))