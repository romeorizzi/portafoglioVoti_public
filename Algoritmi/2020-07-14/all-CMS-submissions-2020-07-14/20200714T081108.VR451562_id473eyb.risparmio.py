"""
* user:  VR451562_id473eyb
* fname: FEDERICO
* lname: GIRELLA
* task:  risparmio
* score: 0.0
* date:  2020-07-14 08:11:08.703936
"""
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from __future__ import print_function
import sys
import math

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

sys.setrecursionlimit(10**9)

def make2N(arr, N):
    # find out log of n
    l2 = int(math.log(N,2))
    if 2**l2 != N:
        # i need to add 0s
        l2 += 1
        target = 2**l2
        for _ in range(N, target):
            arr.append(0)
    return arr, target

def construct(arr):
    global N
    global tree

    # populate leaves
    # each leaf is a dict with: 
    # value, best, sR, sL, len
    # value is only useful in the leaves, not intermediate nodes
    toUpdate = [] # list of nodes whose parents we need to update
    for i in range(N):
        tree[N+i] = {   'best': arr[i],
                        'sR' : arr[i],
                        'sL' : arr[i], 
                        'ln' : 1
                    }
        toUpdate.append(N+i)
    
    # now we generate parents with the update function
    updateParentsOf(toUpdate)

    # return tree

def updateParentsOf(toUpdate):
    # toUpdate contains index of children who have been updated
    fifo = [] # ideally use a proper fifo queue
    for i in toUpdate:
        # for every index in the update list, calculate father
        if not(i//2 in fifo):
            fifo.append(i//2)
    # at this point in the fifo we have the indexes of the 'first layer' fathers
    # need to update, lazy update? 
    while len(fifo) > 0:
        # while we have stuff in the fifo
        cNode = fifo.pop()
        # it's guaranteed to have 2 children
        # cNode.best = max(right.best, left.best, right.sL+left.sR)
        left = cNode * 2
        right = cNode*2 + 1
        changed = False # flag to detect changes, don't update parents of nodes that didn't change anything

        # set this.best
        oldv = tree[cNode]['best']
        # cases:
        # 1- Right of lChild is 1 and left of rChild is 0, no new ranges have been created
        # 2- right of lCHild and left of rChild are 0, no new ranges created
        # 3- right of lChild and left of rChild are 1, one less range
        if tree[left]['sR'] > 0 and tree[right]['sL'] > 0:
            tree[cNode]['best'] = tree[left]['best'] + tree[right]['best'] - 1
        else:
            tree[cNode]['best'] = tree[left]['best'] + tree[right]['best']
        if oldv != tree[cNode]['best']:
            changed = True

        # set this.sL
        oldv = tree[cNode]['sL']
        # if tree[left]['best'] == tree[left]['ln']:
        #     # if the best is the entire length
        #     tree[cNode]['sL'] = tree[left]['best'] + tree[right]['sL']
        # else:
        #     # normal case
        #     tree[cNode]['sL'] = tree[left]['sL']
        
        # no edge cases?
        tree[cNode]['sL'] = tree[left]['sL']
        if oldv != tree[cNode]['sL']:
            changed = True

        # set this.sR
        # oldv = tree[cNode]['sR']
        # if tree[right]['best'] == tree[right]['ln']:
        #     # if the best is the entire length
        #     tree[cNode]['sR'] = tree[right]['best'] + tree[left]['sR']
        # else:
        #     # normal case
        #     tree[cNode]['sR'] = tree[right]['sR']

        tree[cNode]['sR'] = tree[right]['sR']
        if oldv != tree[cNode]['sR']:
            changed = True

        # set this.len need it for first iteration
        # oldv = tree[cNode]['ln']
        # tree[cNode]['ln'] = tree[left]['ln'] + tree[right]['ln']
        # if oldv != tree[cNode]['ln']:
        #     changed = True

        # insert father in the fifo if needed
        if changed and cNode > 1 and not(cNode//2 in fifo):
            fifo.append(cNode//2)

def flip(n):
    global N
    global tree
    # inclusive or exclusive end?
    # for now inclusive
    # they give indexes starting from 0
    # transform into tree indexes
    n += N
    
    toUpdate = [] # list of nodes whose parents need an update
    # this is where the fun begins!
    # need to update: best, sL, sR
    toUpdate.append(n)
    tree[n]['best'] = tree[n]['best'] ^ 1 # binary xor
    tree[n]['sR'] = tree[n]['sR'] ^ 1
    tree[n]['sL'] = tree[n]['sL'] ^ 1
    
    # update parents
    updateParentsOf(toUpdate)

def query(start, end):
    global N
    global tree
    # inclusive or exclusive end?
    # for now inclusive
    # they give indexes starting from 0
    # transform into tree indexes
    start += N
    end += N
    lNode = {'best': 0,
        'sR' : 0,
        'sL' : 0, 
        'ln' : 0}
    rNode = {'best': 0,
        'sR' : 0,
        'sL' : 0, 
        'ln' : 1}
    while start < end:
        if start%2 == 1:
            # need to update by remembering the past
            if lNode['sR'] > 0 and tree[start]['sL'] > 0:
                lNode['best'] = lNode['best'] + tree[start]['best'] - 1
            else:
                lNode['best'] = lNode['best'] + tree[start]['best']
            lNode['sR'] = tree[start]['sR']
            start += 1
        if end%2 == 0:
            if rNode['sL'] > 0 and tree[end]['sR'] > 0:
                rNode['best'] = rNode['best'] + tree[end]['best'] - 1
            else:
                rNode['best'] = rNode['best'] + tree[end]['best']
            rNode['sL'] = tree[end]['sL']
            end -= 1
        start = start//2
        end = end//2
    if start > end:
        # i took 2 leave without a common parent
        if lNode['sR'] > 0 and rNode['sL'] > 0:
            return lNode['best'] + rNode['best'] -1
        else:
            return lNode['best'] + rNode['best']
    else:
        # start == end
        # 3 cases
        # 1- right of lNode is 0 and left of rNode is 0: no intervals lost
        # 2- right of lNode is 1 and left of cNode is 1: 1 interval lost
        # 3- right of cNode is 1 and left of rNode is 1: 1 interval lost
        preRes = lNode['best'] + tree[start]['best'] + rNode['best']
        if lNode['sR'] > 0 and tree[start]['sL'] > 0:
            preRes -=1
        if rNode['sL'] > 0 and tree[start]['sR'] > 0:
            preRes -=1
        return preRes

def operation(vin):
    if vin[0] == '1':
        # flip
        flip(int(vin[1]))
    else:
        # query
        print(query(int(vin[1]), int(vin[2])))

# vin = input().rstrip('\n').split(' ') # N M
# N = int(vin[0])
# M = int(vin[1])

N = 10
M = 10


arr = [0 for _ in range(N)]

# N = 9
# arr = [0, 1, 0, 1, 1, 0, 1, 1, 1]

arr, N = make2N(arr, N)

tree = [{'best': 0,
        'sR' : 0,
        'sL' : 0, 
        'ln' : 1} for _ in range(2*N)]

construct(arr)
# flip(6, 6) # seems to work!!!
# print(query(4,9))
# flip(6)
# print(query(4,9))

# debug
ops = ['2 0 9', '1 5', '1 6', '1 2', '2 1 7', '1 1', '1 3', '1 6', '2 0 8']

for o in ops:
    vin = o.rstrip('\n').split(' ')
    operation(vin)

# while M > 0:
#     vin = input().rstrip('\n').split(' ')
#     operation(vin)
#     M -=1



