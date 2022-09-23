"""
* user:  VR472500
* fname: MATTEO
* lname: MARJANOVIC
* task:  esame_convoglio
* score: 0.0
* date:  2022-09-20 11:07:18.039173
"""
def convoglio(N, lev, nodes, const):
    assert lev >= 0 and lev <= N
    #print(N, lev, nodes, const)
    res = []
    for c in const:
        #print("sono quiiis")
        if c[0] == lev and c[1] in nodes:
            #print("sono qui")
            tmp = nodes[:]
            tmp.remove(c[1])
            ric = convoglio(N, lev+1, tmp, const)
            if lev == N-1:
                res.append([f"{lev} {c[1]}"])
            else:
                for r in ric:
                    res.append([f"{lev} {c[1]}"] + r)
        else:
            continue
    #print("RES", res)

    return res

if __name__ == "__main__":
    in_filename = "input.txt"
    out_filename = "output.txt"
    with open(in_filename, 'r') as in_f:
        lines = in_f.readlines()

    N = int(lines[0].split()[0])
    nodes = [i for i in range(N)]

    const = [[int(s.split()[0]), int(s.split()[1])] for s in lines[1:]]
    turing = [l[:-1] for l in lines[1:N+1]]

    result = convoglio(N, 0, nodes, const)

    with open(out_filename, 'w') as out_f:
        if len(result) == 1 and result[0] == turing:
            out_f.writelines("-1")
        else:
            for r in result:
                if r != turing:
                    for line in r:
                        out_f.writelines(line + "\n")
                    break