"""
* user:  VR434403
* fname: CROSARA
* lname: MARCO
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 08:09:51.456681
"""


def main(n, m, perm, rows):
    for i in range(m):
        if rows[i]["a"] == 1:
            t = perm[rows[i]["b"]]
            perm[rows[i]["b"]] = perm[rows[i]["c"]]
            perm[rows[i]["c"]] = t
        print(perm)
        
        


if __name__ == "__main__":
    with open("att/input0.txt") as att:
        n, m = att.readline().split(" ")
        n = int(n)
        m = int(m)
        perm = att.readline().split(" ")
        for i in range(n):
            perm[i] = int(perm[i])
        rows = []
        for i in range(m):
            t = att.readline().split(" ")
            t[2] = t[2][:-1] # tolgo newline
            row = {"a":0, "b":0, "c":0}
            row["a"] = int(t[0])
            row["b"] = int(t[1]) - 1
            row["c"] = int(t[2]) - 1
            rows += [row]
        print(rows)
        main(n, m, perm, rows)
