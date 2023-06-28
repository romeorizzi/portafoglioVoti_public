"""
* user:  VR477605
* fname: LORENZO
* lname: TABARELLI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:33:06.159171
"""
import sys

sys.setrecursionlimit(10**9)

def find_childs(rad,lista):
    if len(lista) > 3:
        return [lista[2], lista[3]]
    elif len(lista) == 3:
        return [lista[2]]
    else:
        return []

def solver(lista, parent):
    #print(lista)
    result=0
    if len(lista) > 0:
        rad = int(lista[0])
        childs = find_childs(rad, lista)
        #print("SONO CHILDS", childs)
        if childs != []:
            for i,c in enumerate(childs):
                value = solver(lista[i+2:], rad)
                tmp = value + rad
                if tmp > result:
                    result = tmp 
            return result
        else:
            return rad
    return parent

fin = open("input.txt", "r")
pictures = fin.readline()
values  = fin.readline().strip().split()
#print(values)

res1 = solver(values[2:], 0)
res2 = solver(values[3:], 0)

print(res1, res2)

fout = open("output.txt", "w")
if res1 > res2:
    fout.write(str(res1))
else:
    fout.write(str(res2))

fin.close()
fout.close()