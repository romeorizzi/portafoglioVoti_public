"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:24:12.690315
"""
#!/usr/bin/env python3


g, l = tuple(map(int, input().split()))
n = list(map(int, input().split()))

assert len(n) == l

def goal_1():
    cont = 1
    flag = 'c'
    max = 0
    seq_max = 1

    intervalli_c = []
    intervalli_d = []
    int_i = 0
    int_f = 0
    for i in range(l-1):
        #print('cont: ', cont, 'max: ', max)

        if flag == 'c':
            if n[i] < n[i+1]:
                cont += 1
            elif n[i] > n[i+1]:
                cont += 1
                flag = 'd'
                #if int_i != i:
                intervalli_c.append(((int_i, i, i-int_i+1),n[int_i:i+1]))
                int_i = i
        elif flag == 'd':
            if n[i] > n[i+1]:
                cont += 1
            elif n[i] < n[i+1]:
                cont = 2
                flag = 'c'
                #if int_i != i:
                intervalli_d.append(((int_i, i, i-int_i+1),n[int_i:i+1]))
                int_i = i

        if max < cont:
            max = cont
        elif max == cont:
            seq_max += 1

    if flag == 'c':
        intervalli_c.append(((int_i, l-1, l-int_i),n[int_i:]))
    else:
        intervalli_d.append(((int_i, l-1, l-int_i),n[int_i:]))


    if max == 1:
        return l, max

    return 2, max

def goal_2(s):
    if s < 1000000007:
        print(s)
    else:
        print(s%1000000007)

def solve():
    s, m = goal_1()

    if g == 1:
        print(m)
    else:
        goal_2(s)

solve()