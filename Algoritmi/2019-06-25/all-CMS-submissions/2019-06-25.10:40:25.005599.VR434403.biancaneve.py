"""
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  biancaneve
* score: 2.0
* date:  2019-06-25 10:40:25.005599
"""
n, m = map(int, raw_input().split())
perm = map(int, raw_input().split())

for l in range(m):
    row = map(int, raw_input().split())
    #print row
    if row[0] == 1:
        perm[row[1]-1], perm[row[2]-1] = perm[row[2]-1], perm[row[1]-1]
    if row[0] == 2:
        da_ = row[1]
        a_ = row[2]
        for i in range(n):
            if perm[i] >= da_ and perm[i] <= a_:
                result = "YES"
                for j in range(i+1, i+a_-da_):
                    if (perm[j] < da_) or (perm[j] > a_):
                        result = "NO"
                print result
                break
    

