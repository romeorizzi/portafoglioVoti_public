#!/usr/bin/env python3
from sys import stderr, stdout, argv

def solve(n, H):
    # TODO: write here your solution!
    # what follows will be just good enough to respect the intended communication protocol with the server
    A = [13] * n
    Q = 0
    return Q,A    
              
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n = int(input()); assert(1 <= n); assert(n <= 10**6)
        H = list(map(int, input().strip().split())); assert(len(H)==n); assert(all([_ >= 0 for _ in H]))
        if debug_level > 1:
            print(f"# {n=}\n# {H=}", file=stderr)
        Q,A = solve(n,H)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))
