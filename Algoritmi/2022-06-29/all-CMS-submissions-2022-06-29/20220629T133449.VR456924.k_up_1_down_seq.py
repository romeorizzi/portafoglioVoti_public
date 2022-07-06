"""
* user:  VR456924
* fname: NICCOLO
* lname: POZZETTI
* task:  k_up_1_down_seq
* score: 20.0
* date:  2022-06-29 13:34:49.556385
"""
string_list = list()

def create_list(n, k, index=0, val=0, s=""):
    if index == n-1:
        if val == 0:
            string_list.append((s+ " " + str(val)).strip())
            return
        else:
            return

    if val > 0:
        create_list(n, k, index+1, val-1, s+" "+str(val))
    create_list(n, k, index+1, val, s+" "+str(val))
    create_list(n, k, index+1, val+k, s+" "+str(val))

def find_rank(s):
    for i in range(len(string_list)):
        if s == string_list[i]:
            return 1
    return -1

def f():
    return len(string_list) %1000000007

def find_sequence(r):
    return string_list[r%1000000007]


if __name__ == '__main__':
    g, n, k = map(int, input().strip().split())
    create_list(n, k)

    if g == 1:
        print(f())
    if g == 2:
        r = int(input().strip())
        print(find_sequence(r))
    if g == 3:
        in_seq = input().strip()
        find_rank(in_seq)
    if g == 4:
        for s in string_list:
            print(s)
