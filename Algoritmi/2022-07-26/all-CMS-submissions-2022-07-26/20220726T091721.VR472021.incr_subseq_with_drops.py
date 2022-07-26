"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 09:17:21.615678
"""
#!/usr/bin/env python3

from functools import lru_cache



g,n,k = tuple(map(int,input().split()))
lista = list(map(int,input().split()))

#@lru_cache
def fun_max(l,k,x):
    if len(l) == 0:
        return 0

    if k == 0:
        if x < l[0]:
            c = fun_max(l[1:],k,l[0]) + 1
        else:
            c = 0
        
        return max(c, fun_max(l[1:],k,x))
    
    c1=0
    c2=0
    if x < l[0]:
        c1 = fun_max(l[1:],k,l[0]) + 1
    else:
        c2 = fun_max(l[1:],k-1,l[0]) + 1
    c = max(c1,c2)

    return max(c, fun_max(l[1:],k,x))


if g == 0:
    print(fun_max(lista,k,-1))
else:
    print('nobene')
