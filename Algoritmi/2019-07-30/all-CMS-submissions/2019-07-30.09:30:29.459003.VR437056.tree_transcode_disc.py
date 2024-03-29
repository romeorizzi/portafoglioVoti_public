"""
* user:  VR437056
* fname: MARTINI
* lname: MICHELE
* task:  tree_transcode_disc
* score: 40.0
* date:  2019-07-30 09:30:29.459003
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-
from __future__ import print_function
import sys
sys.setrecursionlimit(100000)
if sys.version_info < (3, 0):
    input = raw_input # in python2, raw_input svolge la funzione della primitiva input in python3

class Node:
    def __init__(self, value=1, parent=None):
        self.value = value
        self.parent = parent
        self.children = []
        self.counter = 1

    def set_parent(self, parent):
        self.parent = parent

    def add_child(self, child):
        self.children += [child]
    
    def add_pre_child(self, child):
        self.children = [child] + self.children

    def print_node(self):
        print('value:', self.value, 'parent', end=" ")
        if self.parent is None:
            print('None', end=" ")
        else:
            print(self.parent.value, end=" ")
        for child in self.children:
            print(child.value, end=" ")
        print()

    def pre_visit(self, result):
        result += str(self.value) + ' '
        for child in self.children:
            result = child.pre_visit(result)
        return result
    
    def post_visit(self, result):
        for child in self.children:
            result = child.post_visit(result)
        result += str(self.value) + ' '
        return result


MAX_N = 1000000
seq = list(map(int,input().split()))
if len(seq) < 2:
    exit

tree = [None] * MAX_N
last_node = 0

if seq[0] == 1:
    # Tree root
    tree[last_node] = Node(seq[1])
    current_parent = tree[0]

    # Building of the tree
    for i in range(2, len(seq)):
        print(last_node, end=" ")
        while current_parent.counter == current_parent.value:
            current_parent = current_parent.parent
        current_parent.counter += seq[i]
        last_node += 1
        tree[last_node] = Node(seq[i], current_parent)
        current_parent.add_child(tree[last_node])
        if seq[i] > 1:
            current_parent = tree[last_node]
    
    # Print the result
    print('2', tree[0].post_visit(''))

if seq[0] == 2:
    # First node must have value 1
    tree[last_node] = Node(seq[1])

    for i in range(2, len(seq)):
        if seq[i] > 1:
            current_parent = Node(seq[i])
            counter = 1
            while counter < seq[i]:
                # Create link parent-child
                counter += tree[last_node].value
                tree[last_node].set_parent(current_parent)
                current_parent.add_pre_child(tree[last_node])
                
                # Remove child from array
                tree[last_node] = None
                last_node -= 1
            last_node += 1
            tree[last_node] = current_parent
        else:
            last_node += 1
            tree[last_node] = Node(seq[i])
    
    print('1', tree[0].pre_visit(''))



#for i in range(last_node + 1):
#    tree[i].print_node()







