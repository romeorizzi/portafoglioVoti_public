"""
* user:  VR474565
* fname: MATTIA
* lname: SANTI
* task:  esame_without_grader
* score: 0.0
* date:  2022-09-20 09:40:56.456728
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

def get_inputs():
    n, m = map(int,input().strip().split())
    h = list(map(int,input().strip().split()))
    a = []
    b = []
    c = []
    for _ in range(m):
        A,B,C = map(int,input().strip().split())
        a.append(A)
        b.append(B)
        c.append(C)
    return n,m,h,a,b,c

def print_answer_and_exit(answer):
    print(answer)
    exit(0)

N,M,H,A,B,C = get_inputs()

# begin solution
answer = 0
for i in range(M):
    if(H[B[i]] >= (H[A[i]] + C[i])  ):
        H[B[i]] = H[A[i]] + C[i]

for j in range(N):
    answer += H[j]
# end solution

print_answer_and_exit(answer)