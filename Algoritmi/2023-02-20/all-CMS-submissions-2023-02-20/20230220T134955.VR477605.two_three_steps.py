"""
* user:  VR477605
* fname: LORENZO
* lname: TABARELLI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:49:55.800579
"""
import sys

sys.setrecursionlimit(10**9)

def find_childs(lista, index):
    if len(lista) > index+3:
        return [index+2, index+3]
    elif len(lista) == index+3:
        return [index+2]
    else:
        return []

def solver(lista, memo, index):
    rad = int(lista[index])
    childs = find_childs(lista, index)

    if childs != []:
        for i,c in enumerate(childs):

            if memo[childs[i]] == 0:
                memo = solver(lista, memo, childs[i])
                tmp = memo[childs[i]] + rad
                if tmp >= memo[index]:
                    memo[index] = tmp
            else:
                tmp = memo[childs[i]] + rad
                if tmp >= memo[index]:
                    memo[index] = tmp
        return memo
    else:
        memo[index] = rad

        return memo

fin = open("input.txt", "r")
pictures = fin.readline()
values  = fin.readline().strip().split()
memo1 = [0 for i in range (int(pictures)-2)]
memo2 = [0 for i in range (int(pictures)-3)]

res1 = solver(values[2:], memo1, 0)
res2 = solver(values[3:], memo2, 0)


fout = open("output.txt", "w")
if res1[0] >= res2[0]:
    fout.write(str(res1[0]))
else:
    fout.write(str(res2[0]))

fin.close()
fout.close()