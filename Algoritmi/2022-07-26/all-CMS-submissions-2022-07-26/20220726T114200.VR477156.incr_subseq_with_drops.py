"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 11:42:00.164282
"""
from functools import lru_cache



g, n, k = map(int, input().split())
seq = list(map(int, input().split()))

@lru_cache(maxsize = None)
def maxseq(index, prev, k):
    global seq

    if index >= n:
        return 1
    
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

@lru_cache(maxsize = None)
def n_best_sol(index, prev, k, equals):
    if index >= n:
        return 1, 1
    
    take = (0,0)
    take_wrong = (0,0)
    # Prova a prendere il numero se maggiore
    if seq[index] > prev:
        take = n_best_sol(index+1, seq[index], k, equals)

    # Non prenderlo, sia se è maggiore sia se è minore
    leave = n_best_sol(index+1, prev, k, equals)

    # Se rimangono crolli prova a prenderlo come tale
    if k > 0 and seq[index] <= prev:
        take_wrong = n_best_sol(index+1, seq[index], k - 1, equals)


    max_val = max(1 + take[0], leave[0], 1 + take_wrong[0])
    temp = 0
    if max_val == (take[0] + 1):
        temp+=take[1]
    if max_val == leave[0]:
        temp+=leave[1]
    if max_val == (take_wrong[0] + 1):
        temp+=take_wrong[1]
    return max_val, equals+temp
    



if g == 1:
    n_max = 0
    for i in range(1,n):
        # Se i numeri rimasti sono minori della soluzione ottima mi fermo, non posso più ottenere un ottimo
        if n_max>n-i:
            break
        n_max = max(n_max, maxseq(i, seq[i-1], k))

    print(n_max)
    
if g == 2:

    n_seq_max = 0
    '''
    n_max = 0
    if n > 60:
        n = 60
    for i in range(1,n):
        # Se i numeri rimasti sono minori della soluzione ottima mi fermo, non posso più ottenere un ottimo
        
        
        fun = n_best_sol(i, seq[i-1], k, 0)
        
        if fun[0] == n_max:
            n_seq_max = (fun[1] + n_seq_max)%1000000007
        
        if fun[0] > n_max:
            n_seq_max = fun[1]%1000000007
            n_max = fun[0]
    '''
    print(n_seq_max)