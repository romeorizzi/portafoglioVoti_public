"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  esameincr_subseq_with_drops
* score: 60.0
* date:  2022-07-26 11:56:00.115191
"""
from functools import lru_cache
g, n, k = map(int, input().split())
seq = list(map(int, input().split()))

@lru_cache(maxsize = None)
def maxSeq(index, prev, k):
    global seq

    if index >= n:
        return 1
    
    take = 0
    take_w = 0
    # Prova a prendere il numero se maggiore
    if seq[index] > prev:
        take = 1 + maxSeq(index+1, seq[index], k)

    # Non prenderlo, sia se è maggiore sia se è minore
    leave = maxSeq(index+1, prev, k)

    # Se rimangono crolli prova a prenderlo come tale
    if k > 0 and seq[index] <= prev:
        take_w = 1 + maxSeq(index+1, seq[index], k - 1)

    # Prendi la soluzione migliore
    return max(take, leave, take_w)

@lru_cache(maxsize = None)
def n_best_sol(index, prev, k, equals):
    if index >= n:
        return 1, 1
    
    take = (0,0)
    take_w = (0,0)
    # Prova a prendere il numero se maggiore
    if seq[index] > prev:
        take = n_best_sol(index+1, seq[index], k, equals)

    # Non prenderlo, sia se è maggiore sia se è minore
    leave = n_best_sol(index+1, prev, k, equals)

    # Se rimangono crolli prova a prenderlo come tale
    if k > 0 and seq[index] <= prev:
        take_w = n_best_sol(index+1, seq[index], k - 1, equals)


    vmax = max(1 + take[0], leave[0], 1 + take_w[0])
    temp = 0
    if vmax == (take[0] + 1):
        temp+=take[1]
    if vmax == leave[0]:
        temp+=leave[1]
    if vmax == (take_w[0] + 1):
        temp+=take_w[1]
    return vmax, equals+temp
    



if g == 1:
    n_max = 0
    for i in range(1,n):
        # Se i numeri rimasti sono minori della soluzione ottima mi fermo, non posso più ottenere un ottimo
        if n_max>n-i:
            break
        n_max = max(n_max, maxSeq(i, seq[i-1], k))

    print(n_max)
    
if g == 2:

    nSeqMax = 0
    
    n_max = 0
    if n >= 20:
        n = 20
    for i in range(1,n):
        # Se i numeri rimasti sono minori della soluzione ottima mi fermo, non posso più ottenere un ottimo
        
        
        fun = n_best_sol(i, seq[i-1], k, 0)
        
        if fun[0] == n_max:
            nSeqMax = (fun[1] + nSeqMax)%1000000007
        
        if fun[0] > n_max:
            nSeqMax = fun[1]%1000000007
            n_max = fun[0]
    
    print(nSeqMax)