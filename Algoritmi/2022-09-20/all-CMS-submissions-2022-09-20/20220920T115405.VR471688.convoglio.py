"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:54:05.707143
"""
#!/usr/bin/env python3
import sys
import copy

sys.setrecursionlimit(10 ** 9)

N, M = 0, 0
_CICLE = []
_FOUND = []
_MAXM = 100000
_GRAPH = []
_PREVS = []
_HAS_PREVS = []


def search_unique() -> bool:
    # Scorro tutti i messaggi
    for mess in range(M):
        # Evito tutti i messaggi predecess
        while _PREVS[mess]:
            mess += 1
            if mess + 1 >= N:
                # Ho passato tutti i messaggi, mi fermo qui
                return False
        # Se trovo corrispondenze
        if search(mess, 0):
            # Aggiorno i nuovi found
            for node in range(len(_CICLE)):
                if _CICLE[node] < N:
                    _FOUND[_CICLE[node]] = copy.deepcopy(_CICLE[node])
            #
            for node in range(N):
                if not _FOUND[node]:
                    _FOUND[node] = copy.deepcopy(_GRAPH[node][0])
                print("{} {}".format(node, _FOUND[node] - N))
            # Se sono qui allora ho trovato dei messaggi
            return True
    return False


def search(curr: int, next: int) -> bool:
    if not _PREVS[curr]:
        _HAS_PREVS[curr] = True
        _PREVS[curr] = next + 1
        for u in range(len(_GRAPH)):
            if has_node(curr, u) and _GRAPH[curr][u] != next:
                if search(_GRAPH[curr][u], curr):
                    return True
        _HAS_PREVS[curr] = False
    elif _HAS_PREVS[curr]:
        _CICLE.append(curr)
        _CICLE.append(next)
        while next != curr:
            next = _PREVS[next] - 1
            _CICLE.append(next)
        return True
    return False


def has_node(node: int, index: int) -> bool:
    return node in _GRAPH and index < len(_GRAPH[node])


if __name__ == "__main__":
    N, M = map(int, input().strip().split())
    _HAS_PREVS = [False] * _MAXM
    _FOUND = [0] * _MAXM
    _PREVS = [0] * _MAXM
    _GRAPH = {}
    # Leggo il grafo
    for mess in range(M):
        # Coppia di messaggi
        m1, m2 = map(int, input().strip().split())
        m2 += N  # 'duplico' i messaggi
        if mess < N:
            # I primi N messaggi
            if m1 not in _GRAPH:
                _GRAPH[m1] = []
            _GRAPH[m1].append(m2)
        else:
            # Altri messaggi equivalenti
            if m2 not in _GRAPH:
                _GRAPH[m2] = []
            _GRAPH[m2].append(m1)
    if not search_unique():
        print("-1")
