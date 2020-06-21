"""
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  biancaneve
* score: 2.0
* date:  2019-06-25 10:21:44.210938
"""
n, m = map(int, raw_input().split())
perm = map(int, raw_input().split())
rows = []
for i in range(m):
    t = raw_input().split()
    rows += [[ int(t[0]),  int(t[1]),  int(t[2])]]

for i in range(m):
        if rows[i][0] == 1:
            perm[rows[i][1]-1], perm[rows[i][2]-1] = perm[rows[i][2]-1], perm[rows[i][1]-1]
            #t = perm[rows[i]["b"]-1]
            #perm[rows[i]["b"]-1] = perm[rows[i]["c"]-1]
            #perm[rows[i]["c"]-1] = t
            #print(perm)
        if rows[i][0] == 2:
            da_ = rows[i][1]
            a_ = rows[i][2]
            for i in range(n):
                if perm[i] >= da_ and perm[i] <= a_:
                    result = "YES"
                    for j in range(i+1, i+a_-da_):
                        if (perm[j] < da_) or (perm[j] > a_):
                            result = "NO"
                    print result
                    break
    

