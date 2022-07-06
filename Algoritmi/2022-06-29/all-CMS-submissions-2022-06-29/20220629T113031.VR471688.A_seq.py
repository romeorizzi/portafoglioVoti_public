"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 11:30:31.944045
"""
#!/usr/bin/env python3

elems = []
def a_seq(index, upper, lower, count_up, count_low):
    print(elems[index+1:], upper,lower, count_up, count_low)
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
        s2 = a_seq(index+1, elems[index+2], elem, init, 1)

    return max(s1,s2,count_low+count_up)
    

def ricerca_minori(index):
    el = elems[index]
    index -=1
    r = 0
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
        out.write("{}".format(a_seq(1,elems[1],elems[0],1,1)))




'''
elems = []
def a_seq(index, upper, lower, count_up, count_low):
    print("{} i:{} u:{} l:{} c-u:{} c-l:{}".format(elems[index+1:], index, upper,lower, count_up, count_low))
    if index == len(elems)-1:
        return count_low+count_up
    
    if(elems[index+1]<upper):
        # Elemento è più piccolo del mio upper => aggiorno l'upper oppure lo lascio stare
        s1 = a_seq(index+1, elems[index+1], lower, count_up+1, count_low)
        s2 = a_seq(index+1, upper, lower, count_up, count_low)
        return max(s1,s2)
    
    if(elems[index+1]>lower):
        # Elemento è più grande del mio lower => aggiorno il lower oppure lo lascio stare
        s1 = a_seq(index+1, upper, elems[index+1], count_up, count_low+1)
        s2 = a_seq(index+1, upper, lower, count_up, count_low)
        return max(s1,s2)
    
    if(index+1 != len(elems)-1):
        print("AIA")
        return a_seq(index+2,elems[index+2],elems[index+1],1, 0 if elems[index+2]==elems[index+1] else 1)
    print("EXIT(0)")
    return 0
'''