"""
* user:  VR471688
* fname: NICOLO
* lname: FRETTI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 11:57:54.604640
"""
count = 0
def max_ricordi(index, count):
    if index >= N:
        return count
    two = max_ricordi(index+2, count+piastrelle[index])
    tree = max_ricordi(index+3, count+piastrelle[index])
    return max(two, tree)
    



if __name__=="__main__":
    N = int(input().strip())
    piastrelle = list(map(int, input().strip().split()))
    print(max_ricordi(0,0))
