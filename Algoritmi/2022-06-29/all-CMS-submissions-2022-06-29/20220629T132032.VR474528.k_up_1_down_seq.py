"""
* user:  VR474528
* fname: DAVIDE
* lname: FURLANI
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 13:20:32.906040
"""
#!/usr/bin/env python3

def seq(lst, rem):
    if (lst, rem) in mem:
        return mem[(lst,rem)]
    if (rem == 0):
        if(lst == 0):
            return 1
        else:
            return 0
    if(lst>0):
        mem[lst][rem] = (seq(lst, rem-1) + seq(lst-1, rem-1) + seq(lst+k, rem-1))
        return mem[lst][rem]
    else:
        mem[lst][rem] = seq(lst, rem-1) + seq(lst+k, rem-1)
        return mem[lst][rem]
    


vec = input().split()
goal = int(vec[0])
num_cifre = int(vec[1])
k = int(vec[2])

mem = {}

if goal == 1:
    print(seq(0,num_cifre-1))
