"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:33:42.186988
"""
#!/usr/bin/env python3

def valore(sol, a):
    leng = 1
    for i in range(1, len(sol)):
        if (sol[i-1] <= sol[i]) and sol[i-1]>=0:
            leng += 1
        else:
            if sol[i-1]>0:
                a.append(leng + 1)
                leng = 1
            else: 
                a.append(leng)
                leng = 1




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
    
    sols = []

    sol = []
    for j in range(1, n):
        if (s[j-1] < s[j]):
            sol.append(0)
        elif (s[j-1] == s[j]):
            sol.append(-1)
        else:
            sol.append(1)
    sol.append(1)

    valore(sol, sols)

    if g == 1:
        print(max(sols))
    else:
        dim = max(sols)
        valu = []
        for i in range(n-dim+1):
            valore(sol[i:dim+1], valu)

        start = (valu.index(max(valu)))

        stringa = s[start: start+dim]
        counter = 0

        for i in range(0, start):
            if sol[i] == 0 and s[i]<s[start]:
                counter += 1

        for i in range(start+dim, len(sol)):
            if sol[i] == 1 and s[i]>s[start]:
                counter += 1

        if len(stringa) == 1:
            counter = len(s)



        print(counter)