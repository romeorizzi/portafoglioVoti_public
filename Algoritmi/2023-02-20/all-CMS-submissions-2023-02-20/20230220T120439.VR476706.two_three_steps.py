"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:04:39.148789
"""
MAXIMUM = -10000000

def maximize(l, pos, cost):
    global MAXIMUM
    
    if (pos >= len(l)):
        if (cost > MAXIMUM):
            MAXIMUM = cost
    else:
        maximize(l, pos + 2, cost + l[pos])
        maximize(l, pos + 3, cost + l[pos])



def main():
    global MAXIMUM

    inp = open("input.txt", "r")
    n = int(inp.readline())
    splt = inp.readline().split(" ")

    l = []
    for i in range(n):
        l.append(int(splt[i]))

    maximize(l, 0, 0)

    outp = open("output.txt", "w")
    outp.write(str(MAXIMUM))
    outp.close()    


if __name__ == '__main__':
    main()