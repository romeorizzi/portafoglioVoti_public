"""
* user:  VR451051_id596wge
* fname: ALESSIA
* lname: BODINI
* task:  risparmio
* score: 10.0
* date:  2020-07-14 11:51:21.000772
"""
def create_node(value, sum_sx=0, sum_dx=0, sum_tot=0):
    return {'value': value, 'sum_sx': sum_sx, 'sum_dx': sum_dx, 'sum_tot': sum_tot}


def calc_node(node_sx, node_dx):
    value = int(node_sx['value'] == 1 and node_dx['value'] == 1)
    sum_sx = node_sx['sum_dx'] 
    sum_dx = node_dx['sum_sx']
    sum_tot =  node_sx['sum_tot'] + node_dx['sum_tot'] - 1 if sum_sx >= 1 and sum_dx >= 1 else node_sx['sum_tot'] + node_dx['sum_tot'] 
    return create_node(value, sum_sx, sum_dx, sum_tot)


def build(array, v, left, right):
    if left == right:
        tree[v] = create_node(0)
    else:
        m = int((left + right) / 2)
        build(array, v*2, left, m)
        build(array, v*2+1, m+1, right)
        tree[v] = calc_node(tree[v*2], tree[v*2+1])


def update(v, left, right, pos):
    #print(v, left, right, pos)
    if right < pos or left > pos:
        return
    if left == pos and right == pos:
        if tree[v]['value'] == 1:
            tree[v] = create_node(0)
        else:
            tree[v] = create_node(1, 1, 1, 1)
    else:
        m = int((left + right) / 2)
        if pos <= m:
            update(v*2, left, m, pos)
        elif pos > m:
            update(v*2+1, m+1, right, pos)
        else:
            update(v*2, left, m, pos)
            update(v*2+1, m+1, right, pos)

        tree[v] = calc_node(tree[v*2], tree[v*2+1])


def cons_interval(v, left, right, start, end):
    if right < start or left > end:
        return create_node(0)
    if left >= start and right <= end:
        return tree[v]

    m = int((left + right) / 2)
    '''
    if end <= m:
        node_sx = cons_interval(v*2, left, m, start, min(end, m))
        return calc_node(node_sx, create_node(0))
    elif start > m:
        node_dx = cons_interval(v*2+1, m+1, right, max(start, m+1), end)
        return calc_node(create_node(0), node_dx)
    else:
    '''
    node_sx = cons_interval(v*2, left, m, start, min(end, m))
    node_dx = cons_interval(v*2+1, m+1, right, max(start, m+1), end)
    return calc_node(node_sx, node_dx)


line = input().split()
N = int(line[0])
M = int(line[1])
op = []
sx = []
dx = []
for i in range(M):
    line = input().split()
    op.append(int(line[0]))
    if op[-1] == 1:
        sx.append(int(line[1]))
        dx.append(-1) # assegnamento simbolico, non mi interessa nei calcoli
    else:
        sx.append(int(line[1]))
        dx.append(int(line[2]))

assert M == len(op)
assert M == len(sx)
assert M == len(dx)

# Costruisco il range tree
tree = [create_node(0) for i in range(4*N+1)]
#build([0 for i in range(N)], 1, 0, N-1)
#print(tree)

# Eseguo le operazioni
res = []
for i in range(M):
    if op[i] == 1:
        update(1, 0, N-1, sx[i])
        #print(tree)
        #for i in range(len(tree)):
            #if tree[i] != []:
                #print(i, tree[i]['sum_tot'], end='  ', sep='=')
        #print()
    else:
        res.append(cons_interval(1, 0, N-1, sx[i], dx[i])['sum_tot'])
        #print(res[-1])

for i in res:
    print(i)