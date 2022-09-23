"""
* user:  VR474022
* fname: FILIPPO
* lname: ZICHE
* task:  esame_linear_diff_constraints
* score: 0.0
* date:  2022-09-20 11:47:49.493178
"""

def get_inputs():
    n, m = map(int,input().strip().split())
    h = list(map(int,input().strip().split()))
    a = []
    b = []
    c = []
    for _ in range(m):
        A,B,C = map(int,input().strip().split())
        a.append(A)
        b.append(B)
        c.append(C)
    return n,m,h,a,b,c

def print_answer_and_exit(answer):
    print(answer)
    exit(0)

# Calcola somma di tutte le altezze
def evaluate(config):
    result = 0
    for var in config
        result += val
    return result

# Controlla se la configurazione è valida
def valid(state, H, A, B, C):

    # Non supera altezza massima e non va sotto terra
    for i in range(0, len(state)):
        if state[i] > H[i] or state[i] < 0:
            return False

    # Non viola alcun vincolo
    for v in range(0, len(A)):
        if state[B[v]] > state[A[v]] + C[v]:
            return False

    return True

def solve(n,m,h,a,b,c):
    
    # Possibile configurazione iniziale
    configuration = [ x for x in maxes ]
    limit = 1
    while True:
        mem = {}
        result = iddfs(limit, mem, h, a, b, c)
        if result != -1: return result
        limit += 1


def iddfs(limit, mem, config, H, A, B, C):

    # Se abbiamo giò affrontato questo problema in questa iterazione
    if config in mem:
        return mem[config]

    result = 0

    # Fine della ricorsione, sappiamo che esiste una configurazione
    if limit == 0:
        result = -1

    # La prima soluzione che troviamo è anche la migliore!
    elif valid(config, H, A, B, C):
        result = evaluate(config)

    # Altrimenti continuiamo la ricorsione nelle configurazioni con una torre più bassa
    else:
        for ttl in range(0, len(config)):
            new_config = [x for x in config]
            new_config[ttl] -= 1

            child_result = iddfs(limit - 1, mem, new_config, H, A, B, C);
            if child_result != -1:
                result = child_result
                break

    # Salva risultato
    mem[config] = result
    return result

n,m,h,a,b,c = get_inputs()
print_answer_and_exit(solve(n, m, h, a, b, c))
