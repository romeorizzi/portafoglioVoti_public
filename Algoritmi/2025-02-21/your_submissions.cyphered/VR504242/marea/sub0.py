#!/usr/bin/env python3
from sys import stderr, stdout, argv

def solve(n, H, w):
    left_max = [0] * n 
    right_max = [0] * n 
    water_level = [0] * n 

    left_max[0] = H[0]
    for i in range(1,n):
        left_max[i] = max(left_max[i-1], H[i])

    right_max[n-1] = H[n-1]
    for i in range(n-2,-1,-1):
        right_max[i]=max(right_max[i+1], H[i])

    Q = 0
    for i in range(n):
        min_height = min(left_max[i], right_max[i], w)
        if min_height > H[i]:
            water_level[i] = min_height
            Q+=min_height-H[i]
        else:
            water_level[i] = H[i]
    return Q, water_level

              
if __name__ == "__main__":
    T = int(input())
    for t in range(1, 1 + T):
        n, w = map(int, input().strip().split())
        H = list(map(int, input().strip().split()))
        Q,A = solve(n,H,w)
        print(Q)
        print(" ".join(map(str, A)))
