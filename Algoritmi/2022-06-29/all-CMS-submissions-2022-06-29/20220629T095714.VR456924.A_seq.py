"""
* user:  VR456924
* fname: NICCOLO
* lname: POZZETTI
* task:  A_seq
* score: 23.0
* date:  2022-06-29 09:57:14.803224
"""
def max_len(seq: list, last:int=-1, index:int=0, rising:bool=True):
    if index >= len(seq):
        return 0
    
    res_excluded = max_len(seq, last, index+1, rising)
    if(not rising and seq[index] >= last) or (seq[index] == last):
        return res_excluded
    
    res_included = 1 + max_len(seq, seq[index], index+1, seq[index] > last)
    #print(seq[index])
    return max(res_included, res_excluded)

def f_s(seq: list):
    return _f_s(seq, max_len(seq))

def _f_s(seq: list, cardinality: int, last:int=-1, index:int=0, count:int=0, rising:bool=True):
    if count == cardinality:
        return 1

    if index >= len(seq):
        return 0

    res_excluded = _f_s(seq, cardinality, last, index+1, count, rising)
    if(not rising and seq[index] >= last) or (seq[index] == last):
        return res_excluded
    res_included = _f_s(seq, cardinality, seq[index], index+1, count+1, seq[index] > last)

    return res_excluded + res_included
    

if __name__ == '__main__':
    g, n = tuple(map(int, input().strip().split()))
    sequence = list(map(int, input().strip().split()))
    if g == 1:
        print(max_len(sequence))
    if g == 2:
        print(f_s(sequence))