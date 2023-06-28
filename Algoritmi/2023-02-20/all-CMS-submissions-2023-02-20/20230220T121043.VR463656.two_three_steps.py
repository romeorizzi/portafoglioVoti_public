"""
* user:  VR463656
* fname: GIOVANNI
* lname: DANIELI
* task:  esame_two_three_steps
* score: 80.0
* date:  2023-02-20 12:10:43.784593
"""
N = 0
corridoio = None

MEMORY = {}

with open("input.txt", "r") as i_f:
    N = int(i_f.readline().strip())
    corridoio = list(map(int,i_f.readline().strip().split()))

assert N == len(corridoio)

def corr(i: int):
    if i > len(corridoio) - 1:
        return 0
    if i not in MEMORY:
        MEMORY[i] = corridoio[i] + max(corr(i+2), corr(i+3))
    return MEMORY[i]

with open("output.txt", "w") as o_f:
    o_f.write(str(corr(0)))