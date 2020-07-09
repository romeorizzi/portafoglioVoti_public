"""
* user:  VR445435
* fname: ZEGGIOTTI
* lname: MATTEO
* task:  poldo_sums
* score: 0.0
* date:  2020-06-18 10:25:59.373384
"""
#!/usr/bin/env python3

l = 0
panini = []
gym = []

with open("input.txt", "r") as file:
    line = file.readline()
    l = int(line.rstrip())
    for i in range(l):
        line = file.readline()
        divided = line.split(" ")
        panini.append(int(divided[0].rstrip()))
        gym.append(int(divided[1].rstrip()))


def sum_gym(y, j):
    sum = 0
    for index in range(y, j + 1):
        sum += gym[index]
    return sum


max_sol = []
max_added = 0
solutions = []
memoiz = {}

def discover_new(index, solution):
    global max_added, max_sol
    i = index
    solution.append(i)
    n = panini[i]
    found = False
    for k in range(i - 1, -1, -1):
        m = panini[k]
        sum = sum_gym(k, i - 1)
        if n >= m + sum:
            discover_new(k, solution.copy())
            found = True
    if not found:
        if len(solution) >= max_added:
            max_added = len(solution)
            solutions.append(solution)
            max_sol = solution

for i in range(l):
    discover_new(i, [])

max_sol.reverse()
with open("output.txt", "w") as file:
    file.write(str(max_added))
    file.write("\n")
    for element in max_sol:
        file.write(str(element))
        file.write(" ")
print(max_sol)
