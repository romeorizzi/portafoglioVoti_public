"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  esame_without_grader
* score: 64.0
* date:  2022-09-20 10:50:20.534825
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

N, M = list(map(int,input().split()))
H = list(map(int,input().split()))
CONSTR = []
CONSTR_h = [[] for _ in range(N)]

for i in range(M) :
    A,B,C = list(map(int,input().split()))
    CONSTR.append([A,B,C])
    CONSTR_h[A].append([A,B,C])
    CONSTR_h[B].append([A,B,C])


def calc_constr(h,A,B,C):
    #print(f"{h[B]} <= {h[A]} + {C}")
    return h[B] <= h[A] + C

h = H.copy()
valid_all = False
while not valid_all :
    valid_all = True
    for c in CONSTR :
        res = calc_constr(h,c[0],c[1],c[2])
        #print(res)
        if not res :
            #print(f"changing {h[c[1]]} into {h[c[0]] + c[2]}")
            valid_all = False
            h[c[1]] = h[c[0]] + c[2]
            # recalc ongly h[c[0]] and h[c[1]] constraints

            
            for i in CONSTR_h[c[0]] :
                res = calc_constr(h,i[0],i[1],i[2])
                if not res :
                    #print(f"changing {h[c[1]]} into {h[c[0]] + c[2]}")
                    h[i[1]] = h[i[0]] + i[2]

            for i in CONSTR_h[c[1]] :
                res = calc_constr(h,i[0],i[1],i[2])
                if not res :
                    #print(f"changing {h[c[1]]} into {h[c[0]] + c[2]}")
                    h[i[1]] = h[i[0]] + i[2]




            

# print("recheck constraints")
# for c in CONSTR :
#     res = calc_constr(h,c[0],c[1],c[2])
#     print(res)


#print(f"{h}")
print(sum(h))
exit(0)

