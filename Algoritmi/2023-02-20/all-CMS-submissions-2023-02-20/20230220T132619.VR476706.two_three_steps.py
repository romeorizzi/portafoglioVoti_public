"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:26:19.947887
"""
MAXIMUM = -10000000
L = []
C = []

def maximize(pos, cost):
    global MAXIMUM, L

    if (pos >= len(L)):
        if (cost > MAXIMUM):
            MAXIMUM = cost
    else:
        C.append(pos)
        if (pos + 2 not in C):
            maximize(pos + 2, cost + L[pos])
        if (pos + 3 not in C):
            maximize(pos + 3, cost + L[pos])
        



def main():
    global MAXIMUM, L

    inp = open("input.txt", "r")
    n = int(inp.readline())
    splt = inp.readline().split(" ")

    for i in range(n):
        L.append(int(splt[i]))

    maximize(0, 0)

    outp = open("output.txt", "w")
    outp.write(str(MAXIMUM))
    outp.close()


if __name__ == '__main__':
    main()