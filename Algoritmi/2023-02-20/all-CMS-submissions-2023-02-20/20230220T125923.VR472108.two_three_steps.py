"""
* user:  VR472108
* fname: DAVIDE
* lname: CAMPONOGARA
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 12:59:23.631105
"""
minimum=0


f = open("input.txt", "r")
N = int(f.readline())
path= map(int,f.readline().split())
pathInt=[]
for i in path:
    pathInt.append(int(i))

def avanza(indexStart, sum, passo):
    global minimum
    if(indexStart >= N):
        return
    sum += pathInt[indexStart]
    if(sum > minimum):
        minimum=sum
    avanza(indexStart+passo, sum, 2)
    avanza(indexStart+passo, sum, 3)

avanza(0,0,2)
avanza(0,0,3)
print(minimum)