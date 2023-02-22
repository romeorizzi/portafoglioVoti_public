"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 25.0
* date:  2023-02-20 12:00:13.535763
"""
count = 0
def max_ricordi(index, count):
    if index >= N:
        return count
    two = max_ricordi(index+2, count+piastrelle[index])
    tree = max_ricordi(index+3, count+piastrelle[index])
    return max(two, tree)
    



if __name__=="__main__":
    with open("input.txt", "r") as f:
        N = int(f.readline().strip())
        piastrelle = list(map(int, f.readline().strip().split()))
    with open("output.txt", "w") as f:
        f.write(str(max_ricordi(0,0)))
