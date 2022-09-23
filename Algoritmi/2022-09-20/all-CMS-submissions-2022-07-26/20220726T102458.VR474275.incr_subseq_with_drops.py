"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 10:24:58.493624
"""
from functools import lru_cache

g, n, k = map(int, input().split())
sequence = list(map(int, input().split()))

@lru_cache(maxsize = None)
def maxsequence(index, k):
    global sequence

    if index >= n or k < 0:
       return 0
    
    noDrop = 0
    drop = 0

    if sequence[index] > sequence[index - 1]:
       noDrop = 1 + maxsequence(index + 1, sequence[index], k)

    leave = maxsequence(index + 1, k)

    if k > 0 and sequence[index] <= sequence[index - 1]:
       drop = 1 + maxsequence(index + 1, sequence[index], k - 1)

    return max(noDrop, leave, drop)


if g == 1:
    n_max = 0
    for i in range(1,n):
        if n_max > n - i:
            break
        n_max = max(n_max, 1 + maxsequence(i, k))

    print(n_max)