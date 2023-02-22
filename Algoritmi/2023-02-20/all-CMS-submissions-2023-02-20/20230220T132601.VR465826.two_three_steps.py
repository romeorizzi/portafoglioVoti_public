"""
* user:  VR465826
* fname: FRANCESCO
* lname: BAZZANI
* task:  esame_two_three_steps
* score: 0.0
* date:  2023-02-20 13:26:01.444935
"""
#!/usr/bin/env python3
# -*- coding: latin-1 -*-


def read_text():
    
    with open('input.txt', 'r') as file:
        lines = file.readlines()

        for index, line in enumerate(lines):
            if index == 0:
                n = list(map(int, line.strip().split()))

            else:
                val = tuple(map(int, line.strip().split()))

    return n, val

def write_text(output):

    with open('output.txt', 'w') as f:
        f.write(str(output))



#n = int(input())
#val = map(int,input().split())


def sol(sequence: tuple, memo = {}):

    if sequence in memo.keys():
        return memo[sequence]

    #print(f"chiamo dalla sequenza {sequence}")

    if len(sequence) == 3: 
        #print(f"ritorno {sequence[0]} + {sequence[-1]}")
        return sequence[0] + sequence[-1]
    
    if len(sequence) == 2: 
        #print(f"ritorno {sequence[0]} + {sequence[-1]}")
        return sequence[0] + sequence[-1]
    
    if len(sequence) < 2 and len(sequence) > 0:
        #print(f"ritorno {sequence[0]}")
        return sequence[0]
    

    initial = sequence[0]

    a = 0
    b = 0


    if len(sequence) >= 4:

        #print(f"Initial of {sequence[0]}")

        a = sol(sequence[2:], memo)
        b = sol(sequence[3:], memo)

    memo[sequence] = initial + max(a,b)
        
    return initial + max(a,b)


def main():

    n, val = read_text()
    out = sol(val)
    write_text(out)



if __name__ == '__main__':

    main()

