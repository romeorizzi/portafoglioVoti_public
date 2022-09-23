"""
* user:  VR474275
* fname: MICHELE
* lname: QUARESMINI
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 10:58:18.029856
"""
from functools import lru_cache

g, n, k = map(int, input().split())
seq = list(map(int, input().split()))

@lru_cache(maxsize = None)
def maxseq(index, prev, k):
    global seq

    if index >= n:
       return 0
    
    take = 0
    take_wrong = 0
    # Prova a prendere il numero se maggiore
    if seq[index] > prev:
       take = 1 + maxseq(index+1, seq[index], k)

    # Non prenderlo, sia se è maggiore sia se è minore
    leave = maxseq(index+1, prev, k)

    # Se rimangono crolli prova a prenderlo come tale
    if k > 0 and seq[index] <= prev:
       take_wrong = 1 + maxseq(index+1, seq[index], k - 1)

    # Prendi la soluzione migliore
    return max(take, leave, take_wrong)


if g == 1:
    n_max = 0
    for i in range(1,n):
       # Se i numeri rimasti sono minori della soluzione ottima mi fermo, non posso più ottenere un ottimo
       if n_max>n-i:
         break
       n_max = max(n_max, 1 + maxseq(i, seq[i-1], k))

    print(n_max)