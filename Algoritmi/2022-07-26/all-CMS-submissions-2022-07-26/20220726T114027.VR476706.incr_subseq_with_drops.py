"""
* user:  VR476706
* fname: LUCA
* lname: GUGOLE
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 11:40:27.336799
"""
def task1(s, k): #[6 4 1 2 2 3 4 4 5 9]
                 #[0 1 2 3 4 5 6 7 8 9]
    max_seq = []
    for i in range(0, len(s)):
        current_crolli = 1
        current_seq = [i]
        for j in range(i+1, len(s)):
            if s[i] > s[j]:
                if current_crolli > k:
                    if (len(current_seq) > len(max_seq)):
                        max_seq = current_seq
                    break
                current_crolli += 1
            elif s[j-1] != s[j]:
                current_seq.append(j)
                if j == len(s) - 1:
                    #print(current_seq)
                    return len(current_seq)
        max_seq = current_seq

    #print(max_seq)
    return len(max_seq)




def task2(s, k):
    pass


def main():
    gnk = input()
    gnk_list = gnk.split(" ")
    g = int(gnk_list[0])
    n = int(gnk_list[1])
    k = int(gnk_list[2])

    s_in = input().split(" ")
    s = []
    for i in s_in:
        s.append(int(i))
    
    if g == 1:
        print(task1(s, k))
    elif g == 2:
        task2(s, k)

if __name__ == '__main__':
    main()