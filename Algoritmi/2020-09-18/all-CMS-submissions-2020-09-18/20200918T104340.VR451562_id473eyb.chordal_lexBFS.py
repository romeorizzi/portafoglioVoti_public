"""
* user:  VR451562_id473eyb
* fname: FEDERICO
* lname: GIRELLA
* task:  chordal_lexBFS
* score: 20.0
* date:  2020-09-18 10:43:40.014654
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
import math

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

sys.setrecursionlimit(10**9)

### CHORDAL GRAPHS


class Chordal(object):

    """ Graph data structure, undirected by default. """

    def __init__(self, connections, directed=False):
        self._graph = {}
        self._directed = directed
        self.add_connections(connections)
        self._nodes = set()
        self.getKeys()
        self._order = []
        self._chordality = False
        # self.elimin_order()

    def add_connections(self, connections):
        """ Add connections (list of tuple pairs) to graph """

        for node1, node2 in connections:
            self.add(node1, node2)

    def add(self, node1, node2):
        """ Add connection between node1 and node2 """
        if not(node1 in self._graph):
            # if it's the first time we see this node
            self._graph[node1] = [node2]
        else:
            if not(node2 in self._graph[node1]):
                # if node2 is not already in the connections of node1 
                # self._graph[node1].add(node2)
                self._graph[node1].append(node2)

        
        # if undirected graph
        if not self._directed:
            if not(node2 in self._graph):
                # if it's the first time we see node2
                self._graph[node2] = [node1]
            else:
                if not(node1 in self._graph[node2]):
                    # if node1 is not already in the connections of node1 
                    # self._graph[node2].add(node1)
                    self._graph[node2].append(node1)

    def remove(self, node):
        """ Remove all references to node """

        for n, conns in self._graph.items():  # python3: items(); python2: iteritems()
            try:
                conns.remove(node)
            except KeyError:
                pass
        try:
            del self._graph[node]
        except KeyError:
            pass

    def is_connected(self, node1, node2):
        """ Is node1 directly connected to node2 """

        return node1 in self._graph and node2 in self._graph[node1]
    
    def getKeys(self):
        for k in self._graph:
            self._nodes.add(k)
    

def task1(graph, n):
        """
        Find if 1..n is a perfect elimination order,
        otherwise return the first tuple (j,i,j1) s.t. j1 is neigh of j but not of i and that j1 < i
        """
        alreadyProcessed = set()
        B = [j for j in range(1,n+1)]
        position = {B[i]:i for i in range(len(B))}
        leftNeighbors = {}
        parent = {}
        
        for v in B:
            # nodes processed before the current that have an edge in common are left neighbors
            leftNeighbors[v] = set(graph._graph[v]) & alreadyProcessed
            alreadyProcessed.add(v)
            if leftNeighbors[v]:
                # the parent is the closest left neighbor 
                parent[v] = B[max([position[w] for w in leftNeighbors[v]])]
                # if this node's neighbors (other then the parent itself) are not a subset of the parent's neighbors 
                # it means that it's not a lexOrder
                if not leftNeighbors[v] - {parent[v]} <= leftNeighbors[parent[v]]:
                    return []
        return B

def task2(graph, n):
    """
    Find holes
    """
    alreadyProcessed = set()
    B = [j for j in range(1,n+1)]
    position = {B[i]:i for i in range(len(B))}
    leftNeighbors = {}
    parent = {}
    # check = True
    # smallest = n   
    hol = None 
    for v in B:
            # nodes processed before the current that have an edge in common are left neighbors
            leftNeighbors[v] = set(graph._graph[v]) & alreadyProcessed
            alreadyProcessed.add(v)
            if leftNeighbors[v]:
                # the parent is the closest left neighbor 
                parent[v] = B[max([position[w] for w in leftNeighbors[v]])]
                # if this node's neighbors (other then the parent itself) are not a subset of the parent's neighbors 
                # it means that it's connected to a node that is not connected to all the other neighbors
                # which means the elimination order does not form cliques
                if not leftNeighbors[v] - {parent[v]} <= leftNeighbors[parent[v]]:
                    # check = False
                    # save the smallest node that has a hole
                    hol = v
                    break
    B.reverse()    
    return B, hol

def task3(graph, n):
    """
    Find K
    """
    maxCl = 0
    leftneigh = set() # use set for easy operations
    for k in range(n, 0, -1): # run the elim order reversed
        # clq = set() # each clique is a set so we can do intersections op
        clq = leftneigh & set(graph._graph[k]) # intersection with later vertexes and neighbors = later neighbors
        clq.add(k)
        leftneigh.add(k)
        maxCl = max(maxCl, len(clq))
    return maxCl

def task4(graph, n):
        """
        Find clique with higher number of internal nodes? higher vertex sum? 
        """
        order = [i for i in range(n, 0, -1)]
        # order.reverse()
        maxCl = 0
        # cliques = []
        clique = set()
        leftneigh = set() # use set for easy operations
        for n in order: # run the elim order reversed
            clq = set() # each clique is a set so we can do intersections op
            clq = set(graph._graph[n]) & leftneigh # intersection with later vertexes and neighbors = later neighbors
            clq.add(n)
            leftneigh.add(n)
            ln = len(clq)
            if ln >= maxCl:
                # if we find a clique bigger than all the ones before, only save this one
                # cliques = [clq]
                clique = clq
                maxCl = ln
            # elif len(clq) == maxCl:
            #     # if we another big clique, add it to the list
            #     cliques.append(clq)
        # mini = n+1 # minimun i
        # ret = cliques[0]
        # for c in range(0,len(cliques)):
        #     if min(cliques[c]) < mini:
        #         mini = min(cliques[c])
        #         ret = cliques[c]
        # return maxCl, ret
        return maxCl, clique

def task5(graph, n):
    """
    Find coloring
    """
    # first find how many color i need
    # order = [i for i in range(1, n+1)]
    # order.reverse()
    maxCl = task3(graph, n)
    # now we know thw K
    
    colors = set([i for i in range(1,maxCl+1)]) # in case the whole graph is a clique
    nc = {} # nodes with colors
    preproc = set()
    # run through the reverse order
    for norder in range(n, 0, -1):
        leftneigh = preproc & set(graph._graph[norder])
        used = set()
        for preNode in leftneigh: # left neighbors are the only ones with a color
            # i just have to eliminate their colors
            # available.remove(nc[preNode])
            used.add(nc[preNode])
        preproc.add(norder)
        nc[norder] = min(colors-used)
    print(maxCl)
    for i in range(1,n+1):
        print(str(nc[i])+ " ", end='') 

    # for n in order: # run the elim order reversed
    #     clq = set() # each clique is a set so we can do intersections op
    #     clq = set(graph._graph[n]) & leftneigh # intersection with later vertexes and neighbors = later neighbors
    #     clq.add(n)
    #     leftneigh.add(n)
    #     if len(clq) > maxCl:
    #         # if we find a clique bigger than all the ones before, only save this one
    #         maxCl = len(clq)
    # colors = [i for i in range(1,maxCl+1)]

testing = False
# testing = True
if not testing:
    line = input().strip('\n').split(' ')
    task = int(line[0])
    n = int(line[1])
    m = int(line[2])

    graph = Chordal([])
    # start reading edges
    for i in range(0,m):
        con = input().strip('\n').split(' ')
        graph.add_connections([(int(con[0]), int(con[1]))])
else:
    ### READ FROM FILE FOR TESTING
    fname = 'input99.txt'
    fin = open(fname, 'r')
    line = fin.readline()
    line = line.strip('\n').split(' ')
    task = int(line[0])
    n = int(line[1])
    m = int(line[2])
    graph = Chordal([])
    # start reading edges
    for i in range(0,m):
        con = fin.readline().strip('\n').split(' ')
        graph.add_connections([(int(con[0]), int(con[1]))])

if task == 1:
    pass
elif task == 2:
    B, hol = task2(graph, n)
    if not hol is None:
        print([-1])
        print(hol)
    else:
        for i in B:
            print(str(i) +" ", end='')
        print('\n' + str(2))
elif task == 3:
    print(task3(graph, n))
elif task == 4:
    maxCl, ret = task4(graph,n)
    print(maxCl)
    ret = list(ret)
    ret.sort()
    for i in ret:
        print(str(i)+' ', end='')

elif task == 5:
    task5(graph,n)




# print(graph)
