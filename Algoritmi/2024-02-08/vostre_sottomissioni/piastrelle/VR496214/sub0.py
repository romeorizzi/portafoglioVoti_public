import resource, sys
resource.setrlimit(resource.RLIMIT_STACK, (2**29,-1))
sys.setrecursionlimit(10**6)

arr = [0 for _ in range(10**6)]
arr[0] = 1
arr[1] = 1
for i in range(2, 10*6):
    arr[i] = arr[i-1] + arr[i-2]

def counting(n):
    if n <= 1:
        return 1
    return arr[n]

def ranking(n, P):
    assert n >= 0
    if n == 0:
        return 0
    if n == 1:
        return 0
    if P[:2] == "[]":
        return ranking(n-1, P[2:])
    elif P[:4] == "[--]":
        return counting(n-1) + ranking(n-2, P[4:])
    else:
        assert(False)

def unranking(n, r, mem=""):
    assert n >= 0
    if n == 0:
        return mem
    elif n == 1:
        return unranking(n-1, r, mem+"[]")
    elif r < counting(n-1):
        return unranking(n-1, r, mem+"[]")
    else:
        return unranking(n-2, r-counting(n-1), mem+"[--]")

T = int(input())
for i in range(T):
    n, c, r, u = map(int, input().strip().split())
    if c == 1:
        print(counting(n))
    if r > 0:
        for j in range(0, r):
            P = input()
            print(ranking(n, P))
    if u > 0:
        for k in range(0, u):
            r = int(input())
            print(unranking(n, r))