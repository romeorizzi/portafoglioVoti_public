"""
* user:  VR445435_id495pug
* fname: MATTEO
* lname: ZEGGIOTTI
* task:  risparmio
* score: 35.0
* date:  2020-07-14 12:33:41.581063
"""
#!/usr/bin/env python3

n = 0
n_actions = 0
inp = []
actions = []

n, n_actions = input().rstrip().split(" ")
n = int(n)
n_actions = int(n_actions)
for i in range(n_actions):
    actions.append(input().rstrip().split(" "))

def build_dad(l1, r1, n1, l2, r2, n2):
    [l, r, n] = [0,0,0]
    l = l1
    r = r2
    n = n1+n2
    if r1 and l2:
        n -= 1
    return [l, r, n]
        

def calcola_intervalli(_from, _to):
    _to += 1
    left = len(inp) + _from
    right = len(inp) + _to
    cumulative_l = [False, False, 0]
    cumulative_r = [False, False, 0]
    first_l = True
    first_r = True
    while left < right:
        if left % 2 == 1:
            l,r,n = tree_arr[left]
            if first_l:
                cumulative_l = [l,r,n]
                first_l = not first_l
            else:
                cumulative_l = build_dad(cumulative_l[0], cumulative_l[1], cumulative_l[2],l,r,n)
            left += 1
        if right % 2 == 1:
            right -= 1
            l,r,n = tree_arr[right]
            if first_r:
                cumulative_r = [l,r,n]
                first_r = not first_r
            else:    
                cumulative_r = build_dad(l,r,n, cumulative_r[0], cumulative_r[1], cumulative_r[2])
        left = left // 2
        right = right // 2
    _,_,n = build_dad(cumulative_l[0], cumulative_l[1], cumulative_l[2], cumulative_r[0], cumulative_r[1], cumulative_r[2])
    return n

def update(elements):
    '''
    index = len(inp) + index
    leaf = tree_arr[index]
    if leaf[2] == 1:
        tree_arr[index] = [False,False,0]
    else:
        tree_arr[index] = [True, True, 1]
    dad_index = index // 2

    while dad_index > 0:
        [old_l, old_r, old_n] = tree_arr[dad_index]
        sx_l, sx_r, sx_n = tree_arr[dad_index*2]
        dx_l, dx_r, dx_n = tree_arr[dad_index*2 + 1]
        tree_arr[dad_index] = build_dad(sx_l, sx_r, sx_n, dx_l, dx_r, dx_n)
        if tree_arr[dad_index] == [old_l, old_r, old_n]:
            break
        dad_index = dad_index // 2
    '''
    dads = set()
    for i in elements:
        index = len(inp) + i
        leaf = tree_arr[index]
        if leaf[2] == 1:
            tree_arr[index] = [False,False,0]
        else:
            tree_arr[index] = [True, True, 1]
        dad_index = index // 2

        while dad_index > 0:
            dads.add(dad_index)
            dad_index = dad_index // 2
            if dad_index in dads:
                break
    dads = sorted(dads, reverse=True)
    for dad_index in dads:
        sx_l, sx_r, sx_n = tree_arr[dad_index*2]
        dx_l, dx_r, dx_n = tree_arr[dad_index*2 + 1]
        tree_arr[dad_index] = build_dad(sx_l, sx_r, sx_n, dx_l, dx_r, dx_n)

def build_tree(data_arr, tree_arr):
    middle = len(data_arr)
    for i in range(len(data_arr)):
        tree_arr[middle + i]= [False,False,0] if data_arr[i] == 0 else [True,True,1]
    
    for i in range(len(data_arr) - 1, 0, -1):
        sx_l, sx_r, sx_n = tree_arr[i*2]
        dx_l, dx_r, dx_n = tree_arr[i*2 + 1]
        tree_arr[i] = build_dad(sx_l, sx_r, sx_n, dx_l, dx_r, dx_n)

#resume = 2**(len(inp).bit_length()) - len(inp)
resume = 0
inp = [0 for i in range(resume+n)]
tree_arr = [None for i in range(2*len(inp))]
build_tree(inp, tree_arr)


update_lazy = {}
for action in actions:
    if action[0] == '2':
        update(update_lazy.keys())
        update_lazy.clear()
        print(str(calcola_intervalli(int(action[1]), int(action[2]))))
    if action[0] == '1':
        act = int(action[1])
        if not act in update_lazy:
            update_lazy[act] = 0
        else:
            del update_lazy[act]
            
