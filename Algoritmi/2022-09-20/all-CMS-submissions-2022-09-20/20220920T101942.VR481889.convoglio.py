"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 10:19:42.165129
"""
#!/usr/bin/python3

N, M = list(map(int,input().split()))
MESS = [list(map(int,input().split())) for _ in range(M)]


#print(f"{N}")
#print(f"{M}")
#print(f"{MESS}")

check_M = [False] * N
check_S = [False] * N
valid = [MESS[i] for i in range(N)]


#print(f"{valid}")

MESS = sorted(MESS)


found_valid = False
for i in valid :

    check_M = [False] * N
    check_S = [False] * N
    valid_2 = []
    tmp_MESS = MESS.copy()
    tmp_MESS.remove(i)
    #print(f"{tmp_MESS}")

    for i in tmp_MESS:
        if not check_M[i[0]] and not check_S[i[1]] :
            valid_2.append(i)
            check_M[i[0]] = True
            check_S[i[1]] = True

    #print(f"{check_M}")
    #print(f"{check_S}")
    #print(f"{valid_2}")

    if len(valid_2) == N :
        found_valid = True
        break

if found_valid :
    for i in valid_2:
        print(f"{i[0]} {i[1]}")
else :
    print(-1)

