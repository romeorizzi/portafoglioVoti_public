"""
* user:  VR450781
* fname: MARIN
* lname: JEREGHI
* task:  k_up_1_down_seq
* score: 58.0
* date:  2022-06-29 12:31:47.609282
"""
import sys

BASE = 10**9+7

def list_sequences(n):
    for r in range(num_sequences(n)):
        print(unrank(n,r))

M_num_seq = {}

def num_sequences(n, first_val =0):
    assert n>=1
    global M_num_seq
    if first_val < 0 or first_val >= n:
        return 0
    if n==1:
        return 1
    if (n,first_val) not in M_num_seq:
        M_num_seq[(n,first_val)] = num_sequences(n-1,first_val) + num_sequences(n-1,first_val-1) + num_sequences(n-1,first_val +k) %BASE
    return M_num_seq[(n,first_val)]

def unrank(n,r,first_val=0):
    if n == 1:
        return "0"
    if r< num_sequences(n-1,first_val-1):
        return str(first_val) + " " + unrank(n-1,r,first_val-1)
    
    r = r - num_sequences(n-1,first_val-1)
    if r < num_sequences(n-1, first_val):
        return str(first_val) + " " + unrank(n-1,r,first_val)
    
    r = r - num_sequences(n-1, first_val)
    return str(first_val) + " " + unrank(n-1,r,first_val+k)

def rank(n,s):
    if n == 1:
        return 0

    r = 0
    if s[1] == s[1] -1:
        return r+rank(n-1,s[1:])
    r = r + num_sequences(n-1,s[0]-1)
    if s[1] == s[0]:
        return r + rank(n-1,s[1:])

    r =r+ num_sequences(n-1, s[1:])
    return r + rank(n-1,s[1:])

if __name__ == "__main__":
    g,n,k = map(int, input().split())

    if g == 1:
        print(num_sequences(n))
    elif g == 2:
        r = int(input())
        print(unrank(n,r))
    elif g == 3:
        s = list(map(int, input().split()))
        print(rank(n,s))
    else:
        list_sequences(n)