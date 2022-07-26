"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 11:05:26.427697
"""

def rec(stringa, minimo):
    if len(stringa) == 1:
        return 1
    else:
        try:
            b = stringa.index(minimo)
        except ValueError:
            b=-1
        if b>=0:
            stringa = stringa[b+1:]
        a = min(stringa)
        return 1 + rec(stringa[stringa.index(a)+1:], a)


task, n, drop = input().split(" ")
drop = int(drop)

stringa = []
stringa = (input().split(" "))

st = []
for el in stringa:
    st.append(int(el))

croll = []
tot_drop = 0
prec = st[0]
count = 0
for i in range(1, len(st)):
    if prec > st[i]:
        croll.append(1)
        tot_drop +=1
    else:
        croll.append(0)
    
    if prec == st[i]:
        count += 1

    prec = st[i]

sol = []
"""
try:
    for i in range(0, len(st)):
        if prec == st[i]:
            st.pop(i)
        prec = st[i] 
    
except IndexError:
    pass"""

poss  = [st] * (tot_drop**drop)

last_drop = 0
actual_drop = 0

for stra in poss:
    prec = stra[0]
    for i in range(last_drop, len(stra)):
        if prec > stra[i] and actual_drop < drop:
            stra[i-1] = 0
            last_drop = i-1
            actual_drop += 1


    sol.append(rec(stra, -1))
    actual_drop = 0



print(max(sol))