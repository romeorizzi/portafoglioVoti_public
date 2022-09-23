"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_convoglio
* score: 15.0
* date:  2022-09-20 12:17:50.309735
"""
#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10 ** 9)

N, M = 0, 0
_CICLE = []
_FOUND = []
_MAXM = 200000
_GRAPH = []
_PREVS = []
_HAS_PREVS = []


def search(curr: int, next: int) -> bool:
    if _PREVS[curr]:
        if _HAS_PREVS[curr]:
            _CICLE.append(curr)
            _CICLE.append(next)
            while next != curr:
                next = _PREVS[next] - 1
                _CICLE.append(next)
            return True
        return False
    _HAS_PREVS[curr] = True
    _PREVS[curr] = next + 1
    for u in range(len(_GRAPH)):
        if has_node(curr, u) and _GRAPH[curr][u] != next:
            if search(_GRAPH[curr][u], curr):
                return True
    _HAS_PREVS[curr] = False
    return False


def has_node(node: int, index: int) -> bool:
    return node in _GRAPH and index < len(_GRAPH[node])


def search_unique() -> bool:
    # Scorro tutti i messaggi
    for mess in range(M):
        # Evito tutti i messaggi predecess
        while _PREVS[mess]:
            mess += 1
            if mess >= N:
                # Ho passato tutti i messaggi, mi fermo qui
                return False
        # Se trovo corrispondenze
        if search(mess, -1):
            # Aggiorno i nuovi found
            for node in range(len(_CICLE)):
                if _CICLE[node - 1] < N:
                    _FOUND[_CICLE[node - 1]] = _CICLE[node]
            #
            for node in range(N):
                if not _FOUND[node]:
                    _FOUND[node] = _GRAPH[node][0]
                print("{} {}".format(node, _FOUND[node] - N))
            # Se sono qui allora ho trovato dei messaggi
            return True
    return False


if __name__ == "__main__":
    N, M = map(int, input().strip().split())
    _HAS_PREVS = [False] * _MAXM
    _FOUND = [0] * _MAXM
    _PREVS = [0] * _MAXM
    _GRAPH = {}
    # Leggo il grafo
    for mess in range(M):
        # Coppia di messaggi
        n1, n2 = map(int, input().strip().split())
        n2 += N  # 'duplico' i messaggi
        if mess < N:
            # I primi N messaggi
            if n1 not in _GRAPH:
                _GRAPH[n1] = []
            _GRAPH[n1].append(n2)
        else:
            # Altri messaggi equivalenti
            if n2 not in _GRAPH:
                _GRAPH[n2] = []
            _GRAPH[n2].append(n1)
    if not search_unique():
        print("-1")
