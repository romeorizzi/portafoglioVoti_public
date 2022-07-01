"""
* user:  VR472021
* fname: ANNA
* lname: DALLA VECCHIA
* task:  k_up_1_down_seq
* score: 0.0
* date:  2022-06-29 13:03:01.083965
"""
#!/usr/bin/env python3


g, k, n = tuple(map(int, input().split()))

print(2**(n-k-1))