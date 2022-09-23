"""
* user:  VR472500
* fname: MATTEO
* lname: MARJANOVIC
* task:  esame_without_grader
* score: 4.0
* date:  2022-09-20 09:03:11.711064
"""
def ldc(tow, con):
    for c in con:
        if tow[c[1]] > tow[c[0]] + c[2]:
            tow[c[1]] = tow[c[0]] + c[2]
            return(ldc(tow, con))
    return sum(tow)


if __name__ == "__main__":
    in_filename = "input.txt"
    out_filename = "output.txt"
    with open(in_filename, 'r') as in_f:
        lines = in_f.readlines()
        
    towers = [int(n) for n in lines[1].split()]
    const = []
    for idx in range(len(lines)):
        if idx < 2: continue
        const.append([int(n) for n in lines[idx].split()])

    with open(out_filename, 'w') as out_f:
        out_f.writelines(str(ldc(towers, const)))