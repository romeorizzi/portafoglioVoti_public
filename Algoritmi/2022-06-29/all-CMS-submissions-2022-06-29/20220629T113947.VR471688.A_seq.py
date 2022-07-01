"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:39:47.567169
"""
#!/usr/bin/env python3

elems = []
def a_seq(index, upper, lower, count_up, count_low):
    #print(elems[index+1:], upper,lower, count_up, count_low)
    if index == len(elems)-1:
        return count_low+count_up
    # Qui posso esplorare alcuni casi
    # 1. Il nuovo elemento da analizzare è più grande del mio attuale upper
    # elem = elems[index+1]
    # if(elem > upper):
    #     # Ma allora la mia ricerca si è finita per questo upper
    #     return count_low+count_up
    # 2. L'elemento è minore del mio upper
    s1,s2 = 0,0
    elem = elems[index+1]
    if(elem < upper):
        # Ma allora posso continuare a cercare, però devo cambiare l'upper
        s1 = a_seq(index+1, elem, lower, count_up+1, count_low)
    # Allora intraprendo una nuova ricerca, ma devo stare attento al nuovo upper
    if index+2 != len(elems)-1:
        # Intraprendo una nuova ricarca
        init = ricerca_minori(index+1)
        s2 = a_seq(index+1, elems[index+2], elem, 1 if elems[index+1]!=elems[index+2] else 0, init)

    return max(s1,s2,count_low+count_up)
    

def ricerca_minori(index):
    el = elems[index]
    index -=1
    r = 1
    while index > 0:
        if(el<elems[index]):
            r+=1
        else:
            break
        index -=1
    return r

if __name__=="__main__":
    with open("input.txt") as f:
        n, task = map(int, f.readline().split())
        elems = [int(x) for x in f.readline().split()]
    #print(a_seq(1,elems[1],elems[0],1,1))
    with open("output.txt", "w") as out:
        init = ricerca_minori(0)
        out.write("{}".format(a_seq(1,elems[1],elems[0],1 if elems[0]!=elems[1] else 0,init)))
