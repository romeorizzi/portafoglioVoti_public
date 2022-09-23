"""
* user:  VR479912
* fname: SIMONE
* lname: FERRARI
* task:  esame_without_grader
* score: 0.0
* date:  2022-09-20 12:19:28.219119
"""
#!/usr/bin/env python3
import functools

N, M = map(int, input().split())
H = list(map(int, input().split()))
A = []
B = []
C = []
for m in range(0, M):
    a, b, c = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)

sommaMax = 0

@functools.lru_cache(maxsize=None)
def vincoliOk(altezze):
    for j in range(M):
        if not altezze[A[j]] <= altezze[B[j]] + C[j]:
            return False
    return True

@functools.lru_cache(maxsize=None)
def linear_diff_constraints(altezze, n):
    global sommaMax
    altezze = altezze[:]

    if n<0:
        return 0

    for altezza in H[n]:
        altezze[n] = altezza
        ris = linear_diff_constraints(altezze, n-1)

    if vincoliOk(altezze):
        if sum(ris) > sommaMax:
            sommaMax = sum(ris)
        return sum(ris)
    
    else:
        return 0


print(linear_diff_constraints([0]*N, N-1))


# print(N, M)
# print(H)
# print(A)
# print(B)
# print(C)