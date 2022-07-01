"""
* user:  VR474528
* fname: DAVIDE
* lname: FURLANI
* task:  k_up_1_down_seq
* score: 14.0
* date:  2022-06-29 12:40:13.707784
"""
#!/usr/bin/env python3

def seq(lst, rem):
    if (rem == 0):
        if(lst == 0):
            return 1
        else:
            return 0
    return seq(lst, rem-1)+ (seq(lst-1, rem-1) if lst > 0 else 0)+ seq(lst + k, rem-1)% 1000000007


vec = input().split()
goal = int(vec[0])
num_cifre = int(vec[1])
k = int(vec[2])

if goal == 1:
    print(seq(0,num_cifre-1))