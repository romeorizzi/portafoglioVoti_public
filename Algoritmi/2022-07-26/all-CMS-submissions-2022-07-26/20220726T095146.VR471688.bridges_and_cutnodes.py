"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esamebridges_and_cutnodes
* score: 0.0
* date:  2022-07-26 09:51:46.087675
"""
import copy

def find_bridges(V, adc):
    bridges = []
    done = []
    for u in V:
        for v in adc[u]:
            if (u, v) in done:
                continue
            done.append((u,v));done.append((v,u))
            sub_adc = copy.deepcopy(adc)
            sub_adc[v].remove(u)
            if u in sub_adc[v]:
                sub_adc[v].remove(u)
            # Per ogni adiacente v controllo se u è raggiungibile togliendo ovviamente u dai adc[v]
            if not (is_reachable(u, v, sub_adc)):
                bridges.append((u,v))
    return bridges


# Dato u e v controlla se navigando nella lista di adiacenze riesce a raggiungere u partendo da v
def is_reachable(u, v, adc):
    if(len(adc[v])==0):
        # Non ho adiacenti
        return False
    if(u in adc[v]):
        # Trovato
        return True
    # Propago per tutti gli adiacenti di v il problema
    for v_1 in adc[v]:
        sub = copy.deepcopy(adc)
        sub[v].remove(v_1)
        if(v in sub[v_1]):
            sub[v_1].remove(v)
        if is_reachable(u,v_1,sub):
            return True
    return False


if __name__ == "__main__":
    with open("input.txt") as f:
        T, V, E = map(int, f.readline().split())
        adc = [[]] * V
        edges = []
        vertex = set()
        for _ in range(E):
            u, v = map(int, f.readline().split())
            if len(adc[v]) == 0:
                adc[v] = [u]
            elif u not in adc[v]:
                adc[v].append(u)
            if len(adc[u]) == 0:
                adc[u] = [v]
            elif v not in adc[u]:
                adc[u].append(v)
            vertex.add(v);vertex.add(u)
            edges.append((u,v))
    if (T == 1):
        # bridge problem
        bridges = find_bridges(vertex, adc)
        with open("output.txt", "w") as f:
            for k in edges:
                if k in bridges:
                    f.write("1\n")
                else:
                    f.write("0\n")

