"""
* user:  VR456924
* fname: NICCOLO
* lname: POZZETTI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 10:23:12.246398
"""
def max_len(seq:list, n:int):
    only_rising = [0] * n
    only_rising[0] = 1

    only_falling = [0] * n
    only_falling[-1] = 1

    for i in reversed(range(n)):
        max_found_falling = 0
        for j in reversed(range(i+1, n)):
            if seq[i] > seq[j]:
                max_found_falling = max(max_found_falling, only_falling[j])
        only_falling[i] = max_found_falling + 1

    for i in range(n):
        max_found_rising = 0
        for j in range(i):
            if seq[i] > seq[j]:
                max_found_rising = max(max_found_rising, only_rising[j])
        only_rising[i] = max_found_rising + 1

    max_found = 0
    for i in range(n):
        max_found = max(only_rising[i] + only_falling[i] -1, max_found]
    return max_found

def f_s(seq: list, n:int):
    return _f_s(seq, n, max_len(seq, n))

def _f_s(seq: list, n:int, cardinality: int, last:int=-1, index:int=0, count:int=0, rising:bool=True):
    if count == cardinality:
        return 1

    if index >= n:
        return 0

    res_excluded = _f_s(seq, n, cardinality, last, index+1, count, rising)
    if(not rising and seq[index] >= last) or (seq[index] == last):
        return res_excluded
    res_included = _f_s(seq, n, cardinality, seq[index], index+1, count+1, seq[index] > last)

    return res_excluded + res_included

if __name__ == '__main__':
    g, n = tuple(map(int, input().strip().split()))
    sequence = list(map(int, input().strip().split()))
    if g == 1:
        print(max_len(sequence, n))
    if g == 2:
        print(f_s(sequence, n))
