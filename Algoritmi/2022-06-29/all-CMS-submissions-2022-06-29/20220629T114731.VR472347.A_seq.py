"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:47:31.837270
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
    
    prec = s[0]
    sols = []
    stri = []
    a = 0
    for i in range(1, n):
        sol = [i-1]
        up = True
        for j in range(i + a, n):
            if prec < s[j] and up:
                sol.append(j)
                prec = s[j]
            elif prec > s[j]:
                up = False
                sol.append(j)
                prec = s[j]
        if a == len(s):
            a = 0
        else:
            a += 1

        sols.append(len(sol))
        stri.append(sol)
    
    if g == 1:
        print(max(sols))
    else: 
        counter = 0
        stringa = []
        for a in stri:
            if len(a) >len(stringa):
                stringa = a
        if len(stringa) == 1:
            counter =len(s)
            pass
        else:
            stringa.pop(-1)
        #print(s)
        
        for i in range(0, stringa[0]):
            if s[i]>s[stringa[0]]:
                counter += 1


        for i in range(stringa[0]+len(stringa), len(s)):
            if s[i]<s[stringa[-1]]:
                counter += 1
        


        print(counter%1000000007)