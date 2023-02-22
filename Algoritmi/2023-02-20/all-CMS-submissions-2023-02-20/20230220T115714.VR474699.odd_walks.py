"""
* user:  VR474699
* fname: ALESSANDRO
* lname: RODEGHERO
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:57:14.709584
"""

import sys
sys.setrecursionlimit(10**9)

with open('input.txt','r') as f:
    lines = f.readlines()

N,M,PL,PC = map(int, lines[0].split())
#print('PL',PL)
#print('PC',PC)

#print(N,M,PL,PC)
graph = {}
for i in range(N): graph[i] = {}

for l in lines[1:]:
    h,t,c = l.strip().split()
    graph[int(h)][int(t)]=int(c)

#print(graph)

def cp(par, val): # check par
    if par == 2: return True
    if par == 0:
        if val % 2 == 0: return True
    if par == 1: 
        if val % 2 == 1: return True
    return False

def dfs(graph, node, visited, goal, depth, cost):
    if node not in visited:
        if node == goal:
            if cp(PL, depth) and cp(PC, cost):
                costs.add(cost)
            return False
        visited.add(node)
        for neighbor in graph[node]:
            found = dfs(graph, neighbor, visited, goal, depth+1, cost+graph[node][neighbor])
            #if found:
            #   return True
        return False


def dfs_for_0(graph, node, visited, goal, depth, cost):
    if node not in visited:
        if node == goal and depth > 0:
            if cp(PL, depth) and cp(PC, cost):
                costs.add(cost)
            # print('goal', depth, cost, costs)
            return False
        if node !=0: visited = visited+[node]
        for neighbor in graph[node]:
            #print('fac', node, neighbor, depth, visited)
            found = dfs_for_0(graph, neighbor, visited, goal, depth+1, cost+graph[node][neighbor])
            #if found:
            #   return True
        return False


RES = ''
for g in range(N):
    visited = set()
    costs = set()
    start = 0
    goal = g
    if i == 0: res = dfs_for_0(graph, start, [], goal, 0, 0)
    else: res = dfs(graph, start, visited, goal, 0, 0)
    if len(costs)==0: RES += '-1 '
    else: RES += str(min(costs))+' '
    

#print(RES)
with open('output.txt','w') as f:
    f.write(RES)


#print(min(costs))
#print('res',costs)
