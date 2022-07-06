"""
* user:  VR472347
* fname: MATTEO
* lname: GRELLA
* task:  A_seq
* score: 0.0
* date:  2022-06-29 12:58:11.040622
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
        tot = []
        a = 0
        for i in range(len(s)):
            primo = s[i]
            local = []
            down = False
            for j in range(i+1, len(s)):
                if s[j] < primo:
                    local = [primo, s[j]]
                    down = True
                else:
                    local = [primo, s[j]]
                    
                
                for k in range(j+1, len(s)):
                    if len(local) == max(sols):
                        tot.append(local)
                        local.pop(-1)
                    
                    if (s[k] > local[-1] and not down):
                        local.append(s[k])
                    elif (s[k] < local[-1] and down):
                        local.append(s[k])


        print(len(tot))









