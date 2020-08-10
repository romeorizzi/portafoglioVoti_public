"""
* user:  VR445744_id831qkh
* fname: RICCARDO
* lname: BARTOLOMIOLI
* task:  risparmio
* score: 1.0
* date:  2020-07-14 08:07:42.834775
"""
def combine(left, right):
    parent = dict(tot=0, pref=0, suff=0)
    parent['pref'] = left['pref']
    parent['suff'] = right['suff']
    if left['suff'] == 1 and right['pref'] == 1:
        parent['tot'] = left['tot'] + right['tot'] - 1
    else:
        parent['tot'] = left['tot'] + right['tot']
    return parent


def update(i):
    global tree
    if tree[i]['tot']:
        tree[i]['tot'] = 0
        tree[i]['pref'] = 0
        tree[i]['suff'] = 0
    else:
        tree[i]['tot'] = 1
        tree[i]['pref'] = 1
        tree[i]['suff'] = 1
    while i > 1:
        i //= 2
        tree[i] = combine(tree[2 * i], tree[2 * i + 1])

def query(left, right):
    global tree
    tot = 0

    while left < right:
        if left % 2 == 1:
            if tree[left]['suff'] == 1 and tree[left + 1]['pref'] == 1:
                tot += tree[left]['tot'] - 1
            else:
                tot += tree[left]['tot']
            left += 1
        if right % 2 == 0:
            if tree[right]['pref'] == 1 and tree[right - 1]['suff'] == 1:
                tot += tree[right]['tot'] - 1
            else:
                tot += left[right]['tot']
            right -= 1
        left //= 2
        right //= 2

    if(left == right):
        tot += tree[left]['tot']
    return tot

nm = list(map(int, input().strip().split()))[:]
n = nm[0]
m = nm[1]
tree = [dict(tot=0, pref=0, suff=0)] * 2 * n
for req in range(0,m):
    req = list(map(int, input().strip().split()))[:]
    if req[0] == 1:
        update(n + req[1])
    else:
        print(query(n + req[1],n + req[2]))
