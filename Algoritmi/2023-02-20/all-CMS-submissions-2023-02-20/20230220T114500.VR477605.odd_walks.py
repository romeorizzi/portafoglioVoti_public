"""
* user:  VR477605
* fname: LORENZO
* lname: TABARELLI
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:45:00.593832
"""
import sys

sys.setrecursionlimit(10**9)

def find_path(n, V, parent, result):
    paths = []
    tmp=[]
    #print("SONO tmp", tmp, "SONO RESULT", result)
    if n == 0 and parent != None:
        return [[0]]

    childs = V[n]
    #print("SONO NODE", n , "CHILDS", childs)

    for node in childs:
        tmp = find_path(node, V, n, result)
        for p in tmp:
            new_list=[]
            new_list = [n] + p
            paths.append(new_list)

    return paths

        

def solver(n,V, C, PL, PC):
    paths = find_path(n, V, None, [])
    #print(paths)
    possible_path = []
    for i,p in enumerate(paths):
        
        lenght = len(p)-1
        path_cost = 0
        for i in range(lenght):
            path_cost += C[p[i+1],p[i]]

        #print ("SONO P", p, "LENGTH", lenght%2, "COST", path_cost ,"PL", PL, "PC", PC)
        if PL == 2:
            if PC == 2:
                possible_path.append(path_cost)
            elif PC == 1 and path_cost % 2 == 1 :
                possible_path.append(path_cost)
            elif PC == 0 and path_cost % 2 == 0:
                possible_path.append(path_cost)
        elif PL == 1:
            if PC == 2 and lenght % 2 == 1:
                possible_path.append(path_cost)
            elif PC == 1 and path_cost % 2 == 1 and lenght % 2 == 1:
                possible_path.append(path_cost)
            elif PC == 0 and path_cost % 2 == 0 and lenght % 2 == 1:
                possible_path.append(path_cost)
        elif PL == 0:
            if PC == 2 and lenght % 2 == 0:
                possible_path.append(path_cost)
            elif PC == 1 and path_cost % 2 == 1 and lenght % 2 == 0:
                possible_path.append(path_cost)
            elif PC == 0 and path_cost % 2 == 0 and lenght % 2 == 0:
                possible_path.append(path_cost)
        
    if len(possible_path) == 0:
        return -1
    else: 
        return min(possible_path)

V = {}
C = {}
result=''
fin = open("input0.txt", "r")

N,M,PL,PC = map(int,fin.readline().strip().split())

for i in range (M):
    h, t, c = map(int,fin.readline().strip().split())

    if t in V.keys():
        V[t] += [h]
    else:
        V[t] = [h]
    C[h,t] = c
    #print(h, t, c)

#print(N,M,PL,PC)
#print(V)
#print(C)

for i in range (N):
    value = solver(i, V, C, PL, PC)
    #print(value)
    result+= str(value) + ' '
print(result)
#N,M,PL,PC = map(int,input().split())

#h, t, c = map(int,input().split())
    
