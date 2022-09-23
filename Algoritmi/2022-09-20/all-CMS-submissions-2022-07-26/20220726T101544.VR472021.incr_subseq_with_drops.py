"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 10:15:44.452148
"""
from functools import lru_cache


g, n, k = map(int, input().split())
lista = list(map(int, input().split()))

@lru_cache(maxsize = None)
def fun_max(i, prev, k):
    global lista

    if i >= n:
        return 1
    
    i_sb = 0
    i_corr = 0
    if lista[i] > prev:
        i_corr = 1 + fun_max(i+1, lista[i], k)

    leave = fun_max(i+1, prev, k)

    if k > 0 and lista[i] <= prev:
        i_sb = 1 + fun_max(i+1, lista[i], k - 1)

    return max(i_corr, leave, i_sb)

@lru_cache(maxsize = None)
def n_max(i, prev, k, equals):
    if i >= n:
        return 1, 1
    
    i_sb = (0,0)
    i_corr = (0,0)
    if lista[i] > prev:
        i_corr = n_max(i+1, lista[i], k, equals)

    leave = n_max(i+1, prev, k, equals)

    if k > 0 and lista[i] <= prev:
        i_sb = n_max(i+1, lista[i], k - 1, equals)


    max_val = max(1 + i_corr[0], leave[0], 1 + i_sb[0])
    temp = 0
    if max_val == (i_corr[0] + 1):
        temp+=i_corr[1]
    if max_val == leave[0]:
        temp+=leave[1]
    if max_val == (i_sb[0] + 1):
        temp+=i_sb[1]
    return max_val, equals+temp
    
if g == 1:
    n_max = 0
    for i in range(1,n):
        if n_max>n-i:
            break
        n_max = max(n_max, fun_max(i, lista[i-1], k))

    print(n_max)
    
if g == 2:

    n_lista_max = 0
    n_max = 0
    for i in range(1,n):
        fun = n_max(i, lista[i-1], k, 0)
        
        if fun[0] == n_max:
            n_lista_max = (fun[1] + n_lista_max)
        if fun[0] > n_max:
            n_lista_max = fun[1]
            n_max = fun[0]

    print(n_lista_max)