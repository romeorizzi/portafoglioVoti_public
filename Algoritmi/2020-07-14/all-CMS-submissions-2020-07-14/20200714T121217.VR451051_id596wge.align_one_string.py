"""
* user:  VR451051_id596wge
* fname: ALESSIA
* lname: BODINI
* task:  align_one_string
* score: 2.0
* date:  2020-07-14 12:12:17.864079
"""
def find_string(row, start_col):
    if row >= n:
        return 0
    min_45 = 100000000000000
    count = 0
    times = 0
    for col in range(start_col, m):
        current_cost = 0
        if count == p:
            count = 0
            times += 1
        if times >= 1:
            current_cost = times*cost[p] + cost[count]
        else:
            current_cost = cost[count]
        if a[col] == b[row]:
            if row == n-1 and cost[m-col-1] + current_cost < min_45:
                    min_45 = current_cost + cost[m-col-1]
            elif row < n-1:
                follow = find_string(row+1, col+1)
                if follow == -1:
                    break
                elif follow + current_cost < min_45:
                    min_45 = follow + current_cost
        count += 1
    if min_45 == 100000000000000:
        return -1
    return min_45
   

line = input().split()
m = int(line[0])
n = int(line[1])
p = int(line[2])
line = input()
a = [char for char in line if char != ' ']
line = input()
b = [char for char in line if char != ' ']
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
    print(find_string(0, 0))
    #for i in range(n+1):
        #print(memo[i])
    
                