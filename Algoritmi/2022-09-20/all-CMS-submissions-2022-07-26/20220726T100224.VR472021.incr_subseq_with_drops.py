"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esameincr_subseq_with_drops
* score: 50.0
* date:  2022-07-26 10:02:24.541645
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
        i_corr = fun_max(i+1, lista[i], k) + 1

    nope = fun_max(i+1, prev, k)

    if k > 0 and lista[i] <= prev:
        i_sb =fun_max(i+1, lista[i], k - 1)  + 1

    return max(i_corr, nope, i_sb)

@lru_cache(maxsize = None)
def n_max(i, prev, k, n_max_num):
    if i >= n:
        return 1, 1
    
    i_sb = (0,0)
    i_corr = (0,0)
    if lista[i] > prev:
        i_corr = n_max(i+1, lista[i], k, n_max_num)

    nope = n_max(i+1, prev, k, n_max_num)

    if k > 0 and lista[i] <= prev:
        i_sb = n_max(i+1, lista[i], k - 1, n_max_num)


    max_val = max(1 + i_corr[0], nope[0], 1 + i_sb[0])
    temp = 0
    if max_val == (i_corr[0] + 1):
        temp+=i_corr[1]
    if max_val == nope[0]:
        temp+=nope[1]
    if max_val == (i_sb[0] + 1):
        temp+=i_sb[1]
    return max_val, n_max_num+temp
    

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