"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 80.0
* date:  2023-02-20 12:46:44.664255
"""
from functools import lru_cache

memo = []
piastrelle = []

@lru_cache(maxsize=None)
def max_ricordi(index):
    m1 = m2 = 0
    if index+2 < N:
        m1 = memo[index+2]
    if index+3 < N:
        m2 = memo[index+3]
    memo[index] = piastrelle[index]+ max(m1, m2)
    



if __name__=="__main__":
    
    with open("input.txt", "r") as f:
        N = int(f.readline().strip())
        piastrelle = list(map(int, f.readline().strip().split()))
    memo = [0 for i in range(N)]
    memo[N-1] = piastrelle[N-1]
    memo[N-2] = piastrelle[N-2]
    for i in range(N-3, -1 , -1):
        max_ricordi(i)

    with open("output.txt", "w") as f:
        f.write(str(memo[0]))
