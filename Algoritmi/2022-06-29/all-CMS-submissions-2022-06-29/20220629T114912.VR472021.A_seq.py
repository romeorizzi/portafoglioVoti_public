"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:49:12.095309
"""
#!/usr/bin/env python3

g, l = tuple(map(int, input().split()))
s = list(map(int, input().split()))

assert len(s) == l

max_n=0
max_c=0

def prox(i_prec,i,cont_p,asc,max_n, max_c):
    global max_n, max_c
    if i == l:
        if cont_p > max_n:
            max_n = cont_p
            cont_p = 1
        elif cont_p == max_n:
            max_c += 1
    return max_n, max_c

    if asc and s[i_prec] > s[i]:
        prox(i, i+1, cont_p+1, True)
        prox(i, i+1, cont_p+1, False)
    
    if not asc and s[i_prec] > s[i]:
        prox(i, i+1, cont_p+1, True)

    prox(i_prec, i+1, cont_p+1, asc)


for i in range(l-max_n+1):
    prox(i, i, 1, True)
    prox(i, i, 1, False)

if g == 1:
    print(max_n)
    

