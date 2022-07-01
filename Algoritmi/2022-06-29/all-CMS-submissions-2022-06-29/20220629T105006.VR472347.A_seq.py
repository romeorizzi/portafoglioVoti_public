"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:50:06.753340
"""
if __name__ == "__main__":
    s = []
    g, n = input().split() # g è il goal, n è la lungezza di s
    s = input().split()
    
    g = int(g)
    n = int(n)
    
    
    for i in range(len(s)): 
        s[i] = int(s[i])

    if len(s) >= n:
        s = s[:n]
    
    prec = 0
    counter = 1
    up = True
    print(s)
    for a in range(len(s)):
        if a == 0:
            prec = s[a]
        if s[a]>prec and up :
            counter += 1
            prec = s[a]
        elif s[a]<prec:
            counter += 1
            prec = s[a]
            up = False

    print(int(counter))