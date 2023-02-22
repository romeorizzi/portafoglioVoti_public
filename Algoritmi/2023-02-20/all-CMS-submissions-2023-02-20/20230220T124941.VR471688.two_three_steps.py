"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:49:41.678270
"""
if __name__=="__main__":
    
    with open("input.txt", "r") as f:
        N = int(f.readline().strip())
        piastrelle = list(map(int, f.readline().strip().split()))
    memo = [0 for i in range(N)]
    memo[N-1] = piastrelle[N-1]
    memo[N-2] = piastrelle[N-2]
    for i in range(N-4, -1 , -1):
        memo[i] = piastrelle[i]+ max(memo[i+2], memo[i+3])

    with open("output.txt", "w") as f:
        f.write(str(memo[0]))
