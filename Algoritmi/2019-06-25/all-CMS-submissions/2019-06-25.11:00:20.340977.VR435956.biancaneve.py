"""
* user:  VR435956
* fname: XU
* lname: SUNYI
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 11:00:20.340977
"""
def change_pos(dwarfs, pos1, pos2):
    dwarfs[pos1 - 1], dwarfs[pos2 - 1] = dwarfs[pos2 - 1], dwarfs[pos1 - 1]

def check_con(dwarfs, h1, h2):
    positions = []
    for i in range(h1, h2+1):
        positions.append(position_of(dwarfs, i))
    
    if(contig(positions, len(dwarfs))):
        return "YES"
    else:
        return "NO"

def position_of(dwarfs, i):
    for j in range(0, len(dwarfs)):
        if (int(dwarfs[j]) == i):
            return j

def contig(positions, length):
    min = length - 1
    max = 0
    for i in range(0, len(positions)):
        if (positions[i] > max):
            max = positions[i]
        if (positions[i] < min):
            min = positions[i]
    if (max - min + 1 != len(positions)):
        return False
    
    return True


line1 = input()
line1 = line1.split(" ")
n = line1[0] #numero dei nani
m = int(line1[1]) #numero delle richieste
requests = []

line2 = input()
dwarfs = line2.split(" ") #nani
answers = ""

for i in range(0, m):
    requests.append(input())

for request in requests:
    r = request.split(" ")
    if (r[0] == "1"):
        change_pos(dwarfs, int(r[1]), int(r[2]))
    elif (r[0] == "2"):
        answers += check_con(dwarfs, int(r[1]), int(r[2])) + "\n"

print(answers)