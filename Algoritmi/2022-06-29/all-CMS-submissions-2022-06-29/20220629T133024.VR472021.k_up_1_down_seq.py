"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 13:30:24.276714
"""
#!/usr/bin/env python3

g, k, n = tuple(map(int, input().split()))


mem = {}

def n_s(last,ev):
    if (last, ev) in mem:
        return mem[(last,ev)]
    if (ev == 0) :
        if (last == 0):
            return 1
        else:
            return 0
   
        mem[(last,ev)] = (n_s(last, ev-1)+ (n_s(last-1, ev-1) if last > 0 else 0)+ n_s(last + k, ev-1))

    return mem[(last,ev)]

def seq(last, ev, stri):
    if (ev != 0):
        if last > 0:
            seq(last-1, ev-1, stri + str(last-1))
            seq(last, ev-1, stri + str(last))
            seq(last + k, ev-1, stri + str(last+k))
        elif(last == 0):
            print("0"+stri)

def solve():
    if g == 1:
        print(n_s(0,n-1))
    if g == 4:
        seq(0, n-1, "")

solve()