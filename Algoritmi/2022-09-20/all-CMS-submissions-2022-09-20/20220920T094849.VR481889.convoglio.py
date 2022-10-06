"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 09:48:49.238299
"""
#!/usr/bin/python3

N, M = list(map(int,input().split()))
MESS = [list(map(int,input().split())) for _ in range(M)]

MESS = sorted(MESS)

#print(f"{N}")
#print(f"{M}")
#print(f"{MESS}")

check_M = [False] * N
check_S = [False] * N
valid = []

for i in MESS:
    if not check_M[i[0]] and not check_S[i[1]] :
        valid.append(i)
        check_M[i[0]] = True
        check_S[i[1]] = True

#print(f"{valid}")
for i in valid :
    print(f"{i[0]} {i[1]}")
