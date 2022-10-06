"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esamebridges_and_cutnodes
* score: 18.0
* date:  2022-07-26 12:16:20.289600
"""
import copy

memo_reachables = set()
memo_unreach = set()


def find_bridges(V, adc):
    bridges = {};
    done = []
    for u in V:
        for v in adc[u]:
            if (u, v) in done:
                continue
            done.append((u, v));
            done.append((v, u))
            sub_adc = copy.deepcopy(adc)
            sub_adc[v].remove(u)
            sub_adc[u].remove(v)
            # Per ogni adiacente v controllo se u è raggiungibile togliendo ovviamente u dai adc[v]
            if not (is_reachable(u, v, sub_adc)):
                bridges[str((u, v))] = 1
            else:
                bridges[str((u, v))] = 0
    return bridges


def find_cutnodes(V, adc):
    cutnodes = []
    for u in V:
        if len(adc[u])<2:
            continue
        for v in adc[u]:
            sub_adc = copy.deepcopy(adc)
            sub_adc[v].remove(u)
            sub_adc[u].remove(v)
            if not is_reachable(u, v, sub_adc):
                cutnodes.append(u)
    return cutnodes

def find_components(V, adc):
    components = [0]*len(V)
    for u in V:
        components[u] = find_c(V,u,adc)
    return components

def find_c(V,v,adc):
    r = 0
    visited = [0]*len(V)
    visited[v] = 1
    for u in V:
        if not visited[u]:
            r+=1
            dfs_marked(u, adc, visited)
    return r

def dfs_marked(v, adc, marked):
    marked[v] = 1
    for u in adc[v]:
        if not marked[u]:
            dfs_marked(u,adc,marked)


# Dato u e v controlla se navigando nella lista di adiacenze riesce a raggiungere u partendo da v
def is_reachable(u, v, adc):
    # print(u,v,adc[v],memo_reachables)
    if len(adc[v]) == 0:
        # Non ho adiacenti
        return False
    if (u, v) in memo_reachables or (v, u) in memo_reachables:
        return True
    if u in adc[v]:
        # Trovato
        memo_reachables.add((u, v));
        memo_reachables.add((v, u))
        return True
    # Propago per tutti gli adiacenti di v il problema
    for v_1 in adc[v]:
        sub = copy.deepcopy(adc)
        sub[v].remove(v_1)
        if v in sub[v_1]:
            sub[v_1].remove(v)
        if (u, v_1) in memo_reachables or (v_1, u) in memo_reachables:
            return True
        if (u, v_1) in memo_unreach or (v_1, u) in memo_unreach:
            return False
        if is_reachable(u, v_1, sub):
            memo_reachables.add((u, v))
            memo_reachables.add((u, v_1))
            return True
        else:
            memo_unreach.add((u, v_1))
    return False


if __name__ == "__main__":
    arr = input().split()
    arr = [int(x) for x in arr]
    T = arr[0]
    V = arr[1]
    E = arr[2]
    adc = [[]] * V
    edges = []
    vertex = set()
    for _ in range(E):
        u, v = map(int, input().split())
        if len(adc[v]) == 0:
            adc[v] = [u]
        elif u not in adc[v]:
            adc[v].append(u)
        if len(adc[u]) == 0:
            adc[u] = [v]
        elif v not in adc[u]:
            adc[u].append(v)
        vertex.add(v);
        vertex.add(u)
        edges.append((u, v))
    if (T == 1):
        # bridge problem
        bridges = find_bridges(vertex, adc)
        s = ""
        for k in edges:
            if bridges[str(k)]:
                print(1)
            else:
                print(0)
    if (T == 2):
        # cutnode
        cutnodes = find_cutnodes(vertex, adc)
        for i in range(V):
            if i in cutnodes:
                print(1)
            else:
                print(0)
    if (T==3):
        # components
        components = find_components(vertex, adc)
        for i in components:
            print(i)
