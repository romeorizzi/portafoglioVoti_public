"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:01:18.774284
"""
#!/usr/bin/nv/python3

def goal1(n,s): 
    l = []
    mas = s.index(max(s))
    l.append(s[0])
    h = 0
    for i in range(0,mas-1):
        if s[i] > l[h]:
            l.append(s[i+1])
            h += 1
    if s[mas] != l[h]:
        l.append(s[mas])
    if len(l) > 1:
        for i in range(mas,n-1):
            if s[i+1] < l[h+1]:
                l.append(s[i+1])
                h+=1
    
    return len(l)


def goal2():
    return 2




if __name__ == "__main__":
    g,n = map(int,input().split())
    s = list(map(int,input().split()))

    if g == 1:
        print(goal1(n,s))
    else:
        goal2()
