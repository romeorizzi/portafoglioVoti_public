"""
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:26:53.859656
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-

# Stores minimum-cost of path from source
minSum = 1000000000
  
class graph:
   
   def __init__(self,gdict=None):
      if gdict is None:
         gdict = {}
      self.gdict = gdict

   def edges(self):
      return self.findedges()

   def AddEdge(self, edge):
      (vrtx1, vrtx2, cost)= edge
      if vrtx1 in self.gdict:
         self.gdict[vrtx1].append((vrtx2, cost))
      else:
         self.gdict[vrtx1] = [(vrtx2, cost)]

   def findedges(self):
        edgename = []
        for vrtx in self.gdict:
            for nxtvrtx in self.gdict[vrtx]:
                if {vrtx, nxtvrtx, cost} not in edgename:
                    edgename.append({vrtx, nxtvrtx, cost})
        return edgename

def getMinPathSum(graph: graph, visited, necessary,
                  src, dest, currSum, isStart):
     
    global minSum
     
    # If destination is reached
    if (src == dest and isStart==False):
    
        if PL==0:
            if(currSum%2==0):
                minSum = min(minSum, currSum);
        elif PL==1:
            if(currSum%2==1):
                minSum = min(minSum, currSum);
        else:
            minSum = min(minSum, currSum);

        return;
     
    else:
  
        if(isStart==False):
            visited[src] = True;
  
        for node in graph.gdict[src]:
             
            if not visited[node[0]]:
             
                visited[node[0]] = True;
 
                getMinPathSum(graph, visited,[], node[0],
                              dest, currSum + node[1], False);
 
                visited[node[0]] = False;
         
        visited[src] = False;


f = open("input.txt", "r")
N,M,PL,PC = map(int,f.readline().split())
graph_elements={}
g= graph(graph_elements)
for i in range(0,M):
    u, v, cost= map(int,f.readline().split())
    g.AddEdge((u,v,cost))

visited=[ False for i in range(N + 1)]

for i in range(0,N):
    minSum=1000000000;
    getMinPathSum(g, visited, [], 0 , i, 0, True)
    print(minSum, end =" ")


