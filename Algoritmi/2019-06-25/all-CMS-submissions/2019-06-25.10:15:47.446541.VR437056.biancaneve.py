"""
* user:  VR437056
* fname: MARTINI
* lname: MICHELE
* task:  biancaneve
* score: 0.0
* date:  2019-06-25 10:15:47.446541
"""
import math

class RangeTree:
    def __init__(self, n, arr = []):
        self.MAX   = 0
        self.MIN   = 1
        self.LEFT  = 2
        self.RIGHT = 3
        self.N = 2 ** math.ceil(math.log2(n))
    
        n = self.N
        self.vettorazzo = [[0, 0, 0, 0]] * n * 2
        
        for i in range(n):
            self.vettorazzo[n + i] = [0, 0, i, i]
        
        for i in range(len(arr)):
            self.vettorazzo[n + i][self.MAX] = arr[i]
            self.vettorazzo[n + i][self.MIN] = arr[i]
        for i in range(n-1, 0, -1):
            self.vettorazzo[i] = [self.getmax(i),
                                  self.getmin(i),
                                  self.vettorazzo[i * 2][self.LEFT],
                                  self.vettorazzo[i * 2 + 1][self.RIGHT]]
    
    def getmax(self, pos):
        if (2 * pos) > len(self.vettorazzo):
            return self.vettorazzo[pos][self.MAX]
        return max(self.vettorazzo[pos * 2][self.MAX],
                   self.vettorazzo[pos * 2 + 1][self.MAX])

    def getmin(self, pos):
        if (2 * pos) > len(self.vettorazzo):
            return self.vettorazzo[pos][self.MIN]
        return min(self.vettorazzo[pos * 2][self.MIN],
                   self.vettorazzo[pos * 2 + 1][self.MIN])

    def update_value(self, pos, diff):
        pos += self.N
        self.vettorazzo[pos][self.MAX] += diff
        self.vettorazzo[pos][self.MIN] = self.vettorazzo[pos][self.MAX]

        pos //= 2
        while pos > 0:
            self.vettorazzo[pos][self.MAX] = self.getmax(pos)
            self.vettorazzo[pos][self.MIN] = self.getmin(pos)
            pos //= 2
    
    def update(self, pos, new_value):
        pos -= 1
        self.update_value(pos, new_value - self.vettorazzo[self.N + pos][self.MAX])
    
    
    def max_in_range(self, node, l, r):
        if (l == self.vettorazzo[node][self.LEFT]) and (r == self.vettorazzo[node][self.RIGHT]):
            return self.vettorazzo[node][self.MAX]
        elif r <= self.vettorazzo[node * 2][self.RIGHT]:
            return self.max_in_range(node * 2, l, r)
        elif l >= self.vettorazzo[node * 2 + 1][self.LEFT]:
            return self.max_in_range(node * 2 + 1, l, r)
        else:
            return max(self.max_in_range(node * 2, l, self.vettorazzo[node * 2][self.RIGHT]),
                       self.max_in_range(node * 2 + 1, self.vettorazzo[node * 2 + 1][self.LEFT], r))
            
    def min_in_range(self, node, l, r):
        if (l == self.vettorazzo[node][self.LEFT]) and (r == self.vettorazzo[node][self.RIGHT]):
            return self.vettorazzo[node][self.MIN]
        elif r <= self.vettorazzo[node * 2][self.RIGHT]:
            return self.min_in_range(node * 2, l, r)
        elif l >= self.vettorazzo[node * 2 + 1][self.LEFT]:
            return self.min_in_range(node * 2 + 1, l, r)
        else:
            return min(self.min_in_range(node * 2, l, self.vettorazzo[node * 2][self.RIGHT]),
                       self.min_in_range(node * 2 + 1, self.vettorazzo[node * 2 + 1][self.LEFT], r))
        
    
    # Type: 0 == max, 1 == min
    def query(self, l, r, type):
        l -= 1
        r -= 1
        if (r < l) or (r >= self.N) or (l < 0):
            print('ERRORE')
            return -1
        if type == 0:
            return self.max_in_range(1, l, r)
        else:
            return self.min_in_range(1, l, r)
        
    
    def pretty_print(self):
        counter = 0
        bound = 1
        for i in range(1, self.N):
            counter += 1
            print(self.vettorazzo[i], end = " ")
            if counter == bound:
                print()
                counter = 0
                bound *= 2
        for i in range(self.N, self.N * 2):
            counter += 1
            print([self.vettorazzo[i][self.MAX], self.vettorazzo[i][self.LEFT]], end=' ')
            if counter == bound:
                print()
                counter = 0
                bound *= 2

def found_all(dwarves, start, end, maximum, minimum):
    bias = minimum
    length = maximum - minimum
    
    result = [0] * (length + 1)
    for i in range(start, end + 1):
        result[dwarves[i] - bias] = 1

    if 0 in result:
        return 0
    else:
        return 1


n_and_m = input("N ed M: ").split(' ')
n = int(n_and_m[0])
m = int(n_and_m[1])

dwarves_input = input("Nani: ").split(' ')
dwarves = [0] * n
for i in range(n):
    dwarves[i] = int(dwarves_input[i])
tree = RangeTree(n, dwarves)

result_array = [0] * m
counter = 0
for i in range(m):
    instruction = input('Query: ').split(' ')
    pos_1 = int(instruction[1])
    pos_2 = int(instruction[2])
    
    if instruction[0] == '1':
        dwarves[pos_1 - 1], dwarves[pos_2 - 1] = dwarves[pos_2 - 1], dwarves[pos_1 - 1]
        tree.update(pos_1, dwarves[pos_1 - 1])
        tree.update(pos_2, dwarves[pos_2 - 1])
    else:
        if pos_1 > pos_2:
            pos_1, pos_2 = pos_2, pos_1
        maximum = tree.query(pos_1, pos_2, 0)
        minimum = tree.query(pos_1, pos_2, 1)
        result_array[counter] = found_all(dwarves, pos_1 - 1, pos_2 - 1, maximum, minimum)
        counter += 1

for i in range(counter):
    if result_array[i] == 0:
        print('NO')
    else:
        print('YES')


    
