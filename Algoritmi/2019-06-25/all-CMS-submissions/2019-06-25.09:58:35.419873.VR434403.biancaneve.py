"""
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  biancaneve
* score: 2.0
* date:  2019-06-25 09:58:35.419873
"""
n, m = map(int, raw_input().split())
perm = map(int, raw_input().split())
rows = []
for i in range(m):
    t = raw_input().split()
    row = {"a":0, "b":0, "c":0}
    row["a"] = int(t[0])
    row["b"] = int(t[1])
    row["c"] = int(t[2])
    rows += [row]

for i in range(m):
        if rows[i]["a"] == 1:
            t = perm[rows[i]["b"]-1]
            perm[rows[i]["b"]-1] = perm[rows[i]["c"]-1]
            perm[rows[i]["c"]-1] = t
            #print(perm)
        if rows[i]["a"] == 2:
            da_ = rows[i]["b"]
            a_ = rows[i]["c"]
            for i in range(n):
                if perm[i] >= da_ and perm[i] <= a_:
                    result = "YES"
                    for j in range(i+1, i+a_-da_):
                        if (perm[j] < da_) or (perm[j] > a_):
                            result = "NO"
                    print(result)
                    break
    

