"""
* user:  VR451051_id596wge
* fname: ALESSIA
* lname: BODINI
* task:  align_one_string
* score: 0.0
* date:  2020-07-14 10:30:36.145645
"""
def find_string(row, start_col, count):
    if row == n:
        return 0
    output = []
    min_45 = 1000000
    count = 0
    for col in range(m):
        if a[col] != b[row]:
            count += 1
        else:
            if row < n:
                if memo[row][col] == 0:
                    memo[row][col] = find_string(row+1, col+1, count-1)
                follow = memo[row+1][col+1]
            if ((row == n and cost[count] < min_45) or 
                (cost[follow] + cost[count] < min_45)):
                min_45 = cost[follow] + cost[count]
    return min_45
   

line = input().split()
m = int(line[0])
n = int(line[1])
p = int(line[2])
line = input()
a = [char for char in line]
a = a[:-1]
line = input()
b = [char for char in line]
b = b[:-1]
cost = []
line = input().split()
for i in range(p+1):
    cost.append(int(line[i]))

assert m == len(a)
assert n == len(b)
assert p+1 == len(cost)

memo = [[0 for i in range(m+1)] for j in range(n+1)]
for i in reversed(range(n)):
    found = False
    for j in reversed(range(m)):
        if b[i] == a[j] or found == True:
            memo[i][j] = memo[i+1][j+1] + 1
            found = True

output = [[] for i in range(n)]
count = n

if memo[0][0] < n:
    print(-1)
else:
    memo = [[0 for i in range(m+1)] for j in range(n+1)]
    print(find_string(0, 0, n))
    
                