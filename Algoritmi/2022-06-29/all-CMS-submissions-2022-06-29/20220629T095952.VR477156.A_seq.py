"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:59:52.122467
"""
def goal1(n,s): 
    maxlen = 0
    for j in range(n):
        l = []
        massimo = 0
        maxindex = 0
        l.append(s[j])
        h = 0
        for i in range(j+1,n):           
            if s[i] > l[h]:
                l.append(s[i])
                
            else:      
                massimo = l[h]
                maxindex = i       
                break
            h += 1
        for i in range(maxindex, n):          
            if s[i] < l[h]:           
                l.append(s[i])
                print(s[i])
            else:
                break
            h += 1

        length = len(l)
        if maxlen < length:
            maxlen = length

    return maxlen


def goal2():
    return 2




if __name__ == "__main__":
    g,n = map(int,input().split())
    s = list(map(int,input().split()))

    if g == 1:
        print(goal1(n,s))
    else:
        goal2()
