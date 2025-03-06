
from sys import stderr, stdout, argv

def digasx(i,H):
    max2 = 0
    for j in range(0,i):
        if H[j] > H[i]:
            if H[j] > max2:
                max2 = H[j]
    return max2


def digadx(i,H):
    max2 = 0
    for j in range(i+1,n):
        if H[j] > H[i]:
            if H[j] > max2:
                max2 = H[j]
    return max2




def solve(n, H):
    # TODO: write here your solution!
    # what follows will be just good enough to respect the intended communication protocol with the server
    A = [13] * n
    Q = 0

    w = int(input())
    

    if w == 0:
        return Q,H

    A[0] = H[0]
    A[n-1] = H[n-1]

    maxs = 0
    maxd = 0

    """for i in range(1, n-1):
        if H[i] >= w:
            A[i] = H[i]
        for j in range(0, i-1):
            if (H[j] >= H[j+1]):
                maxs = H[j]
        print("maxs: ",maxs)
        for j in range(i+1, n):
            if (H[j] >= H[j-1]):
                maxd = H[j]
        print("maxd: ",maxs)"""


    for i in range(1,n-1):
        if H[i] >= w:
            A[i] = H[i]
        maxs = digasx(i,H)
        maxd = digadx(i,H)
        if (maxs != 0 and maxd != 0):
            A_final = min(maxs, maxd)-H[i]
            Q = Q + A_final
            A[i] = A[i] + A_final
  
    
    return Q,A    
              
if __name__ == "__main__":
    debug_level = 0
    if len(argv) == 2:
        debug_level = int(argv[1])
    T = int(input())
    for t in range(1, 1 + T):
        if debug_level > 0:
            print(f"#\n# Testcase {t}:", file=stderr)
        n,w = list(map(int(input()).strip().split())); assert(1 <= n); assert(n <= 10**6)
        H = list(map(int, input().strip().split())); assert(len(H)==n); assert(all([_ >= 0 for _ in H]))
        if debug_level > 1:
            print(f"# {n=}\n# {H=}", file=stderr)
        Q,A = solve(n,H)
        if debug_level > 2:
            print(f"# {Q=}, {A=}", file=stderr)
        print(Q)
        print(" ".join(map(str, A)))
