"""
* user:  VR477156
* fname: MATTIA
* lname: BURATI
* task:  esamebridges_and_cutnodes
* score: 48.0
* date:  2022-07-26 10:34:30.072618
"""
import math
from collections import defaultdict

class Graph:
    def __init__(self,vertices,edges):
        self.V = vertices
        self.E = edges
        self.graph = defaultdict(list)
        self.Time = 0
        self.edgeList = []

    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)
        self.edgeList.append([u,v])

    def APUtil(self,u,visited,ap,parent,low,disc):
        children = 0
        visited[u] = True
        disc[u] = self.Time
        low[u] = self.Time
        self.Time +=1 

        for v in self.graph[u]:
            if visited[v] == False:
                parent[v] = u
                children += 1
                
                self.APUtil(v,visited,ap,parent,low,disc)
                
                low[u] = min(low[u],low[v])

                if parent[u] == -1 and children > 1:
                    ap[u] = True
                
                if parent[u] != -1 and low[v] >= disc[u]:
                    ap[u] = True
            elif v != parent[u]:
                low[u] = min(low[u],disc[v])

    def p():
        print(graph)


    def AP(self):
        visited = [False] * (self.V)
        disc = [float("Inf")] * (self.V)
        low = [float("Inf")] * (self.V)
        parent = [-1] * (self.V)
        ap = [False] * (self.V)

        for i in range(self.V):
            if visited[i] == False:
                self.APUtil(i,visited,ap,parent,low,disc)
        
        for val in ap:
            if val == True:
                print(1)
            else:
                print(0)
    
    
    def bridgeUtil(self,u,visited,bridges,parent,low,disc):
        visited[u] = True
        disc[u] = self.Time
        low[u] = self.Time
        self.Time +=1 
        for v in self.graph[u]:
            if visited[v] == False:
                parent[v] = u
                
                self.bridgeUtil(v,visited,bridges,parent,low,disc)
                
                low[u] = min(low[u],low[v])

                if low[v] > disc[u]:
                    bridges.append([u,v])
                    bridges.append([v,u])

            elif v != parent[u]:
                low[u] = min(low[u],disc[v])

    def bridge(self):
        visited = [False] * (self.V)
        disc = [float("Inf")] * (self.V)
        low = [float("Inf")] * (self.V)
        parent = [-1] * (self.V)
        bridges = []
        pb = [0] * (self.E)

        for i in range(self.V):
            if visited[i] == False:
                self.bridgeUtil(i,visited,bridges,parent,low,disc)
        
        for i in bridges:
            try:
                ind = self.edgeList.index(i)
                pb[ind] = 1
            except:
                continue
        for i in pb:
            print(str(i))
        

if __name__ == "__main__":
    
    sel = input().split(" ")
    v = int(sel[1])
    e = int(sel[2])
    g1 = Graph(v,e)

    for i in range(e):
        edge = input().split(" ")
        u = int(edge[0])
        v = int(edge[1])
        g1.addEdge(u,v)

    if sel[0] == "1":
        g1.bridge()
    if sel[0] == "2":
        g1.AP()

    '''
    
    
    g2 = Graph(10,13)
    g2.addEdge(0,1)
    g2.addEdge(1,2)
    g2.addEdge(1,3)
    g2.addEdge(1,4)
    g2.addEdge(1,5)
    g2.addEdge(1,6)
    g2.addEdge(2,3)
    g2.addEdge(4,5)
    g2.addEdge(5,6)
    g2.addEdge(6,7)
    g2.addEdge(7,8)
    g2.addEdge(7,9)
    g2.addEdge(8,9)
    bridges = g2.bridge()
    '''

    
    