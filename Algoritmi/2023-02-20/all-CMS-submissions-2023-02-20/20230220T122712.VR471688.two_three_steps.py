"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:27:12.490326
"""
memo = []
piastrelle = []
def max_ricordi(index, count):
    global piastelle
    if index >= N:
        return count
    if memo[index]!= -1:
        return memo[index]
    two = max_ricordi(index+2, count+piastrelle[index])
    tree = max_ricordi(index+3, count+piastrelle[index])

    memo[index] = max(two, tree)
    return memo[index]
    



if __name__=="__main__":
    
    with open("input.txt", "r") as f:
        N = int(f.readline().strip())
        piastrelle = list(map(int, f.readline().strip().split()))
    memo = [-1 for i in range(N+1)]
    with open("output.txt", "w") as f:
        f.write(str(max_ricordi(0,0)))
