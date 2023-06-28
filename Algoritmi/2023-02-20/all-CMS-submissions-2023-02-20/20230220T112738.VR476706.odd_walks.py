"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_odd_walks
* score: 0.0
* date:  2023-02-20 11:27:38.449114
"""
N = 0
M = 0
PL = 0
PC = 0
A = {}

output = ""

PENDING_COST = 100000000
PENDING_LENGTH = 0


def update_pendings(cost, l):
    global PENDING_LENGTH, PENDING_COST

    if (cost < PENDING_COST):
        PENDING_COST = cost
        PENDING_LENGTH = l


def walk(node, end_node, l, cost, visited):
    if node == end_node:
        update_pendings(cost, l)
    else:
        adj = A[node]
        for a in adj:
            if (a not in visited):
                visited.append(a)
                walk(a[1], end_node, l+1, cost + a[2], visited)



def search():
    global N, PENDING_LENGTH, PENDING_COST, output

    for i in range(N):
        walk(0, i, 0, 0, [])
        if PL == 2 or PENDING_LENGTH % 2 == 0:
            if PC == 2 or PENDING_COST % 2 == 0:
                #print(str(PENDING_COST), end=" ")
                output += str(PENDING_COST) + " "
            else:
                #print("-1", end=" ")
                output += "-1 "
        else:
            output += "-1 "

        PENDING_LENGTH = 0
        PENDING_COST = 100000000
            


def main():
    global N, M, PL, PC, output

    inp = open("input.txt", "r")
    l1 = inp.readline().split(" ")
    N = int(l1[0])
    M = int(l1[1])
    PL = int(l1[2])
    PC = int(l1[3])

    for i in range(M):
        li = inp.readline().split(" ")
        u = int(li[0])
        v = int(li[1])
        c = int(li[2])
        if (u not in A):
            A[u] = [[u, v, c]]
        else:
            A[u].append([u, v, c])
    inp.close()

    search()

    outp = open("output.txt", "w")
    outp.write(output)
    outp.close()


if __name__ == '__main__':
    main()