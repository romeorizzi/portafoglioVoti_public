"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esamebridges_and_cutnodes
* score: 7.0
* date:  2022-07-26 10:11:10.194181
"""
passed = []

def task1(g, e_list):
    for e in e_list:
        removed_u = e[0]
        removed_v = e[1]
        g[removed_u].remove(removed_v)  # tolgo a g un arco

        if not path_to_v(g, removed_u, removed_v):
            print(1)
        else:
            print(0)
        
        g[removed_u].append(removed_v) # rimetto l'arco in g


def task2(g):
    g1 = g.copy()
    pass


def task3(g):
    g1 = g.copy()
    pass


def read_make_graph(n, m):
    g = {}
    e_list = []
    for i in range(0, n):
        g[i] = []
    for i in range(0, m):
        coppia = input().split(" ")
        u = int(coppia[0])
        v = int(coppia[1])
        g[u].append(v)
        g[v].append(u)
        e_list.append([u, v])
    
    return g, e_list

def path_to_v(g, u, v):
    global passed
    passed = []
    if len(g[u]) == 0 or len(g[v]) == 0:
        return False
    else:
        path_to_v_rec(g, u, v)
        if v in passed:
            return True
        else:
            return False

def path_to_v_rec(g, u, v):
    global passed
    if v in g[u]:
        passed.append(v)
        return
    else:
        for c in g[u]:
            if c not in passed:
                passed.append(c)
                path_to_v_rec(g, c, v)

#    for c in g[u]:
#        if c not in passed:
#            if c == v:
#                passed.append(v)
#                return
#            else:
#                passed.append(c)
#                path_to_v_rec(g, c, v)
        


def main():
    tnm = input()
    tnm_list = tnm.split(" ")
    t = int(tnm_list[0])
    n = int(tnm_list[1])
    m = int(tnm_list[2])

    g, e = read_make_graph(n, m)

    if t == 1:
        task1(g, e)
    elif t == 2:
        task2(g)
    elif t == 3:
        task3(g)



if __name__ == '__main__':
    main()