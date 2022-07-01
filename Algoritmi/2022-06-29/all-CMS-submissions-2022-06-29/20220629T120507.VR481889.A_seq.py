"""
* user:  VR481889
* fname: LORENZO
* lname: MIOSO
* task:  A_seq
* score: 0.0
* date:  2022-06-29 12:05:07.255726
"""
#!/usr/bin/env python3

def A_seq_len(s) :
    if len(s) == 0 : 
        return 0
    if len(s) == 1 :
        return 1
    else :
        res = 0
        for i in range(len(s)) :
            res1 = max_inc_len(s[:i+1])
            #print("max_inc_len(" + str(s[:i+1]) + ")=" + str(res1), end=" ")
            #print(" | " + str(s[i]) + " | ", end=" ")
            res2 = max_k_dec_len(s[i+1:],s[i]-1)
            #print("max_k_dec_len(" + str(s[i+1:])+ "," + str(s[i]-1) + ")=" + str(res2), end=" ")
            #print("res = " +  str(res1 + res2))
            res = max(res, res1 + res2)

        return res

def count_A_seq_len(s) :
    if len(s) == 0 : 
        return 0
    if len(s) == 1 :
        return 1
    else :
        res = 1
        res_table = []
        for i in range(len(s)) :
            res1 = max_inc_len(s[:i+1])
            #print("max_inc_len(" + str(s[:i+1]) + ")=" + str(res1), end=" ")
            #print(" | " + str(s[i]) + " | ", end=" ")
            res2 = max_k_dec_len(s[i+1:],s[i]-1)
            #print("max_k_dec_len(" + str(s[i+1:])+ "," + str(s[i]-1) + ")=" + str(res2), end=" ")
            #print("res = " +  str(res1 + res2))
            res_table.append(res1 + res2)
            if res1 + res2 > res :
                res = res1 + res2
        #print(res_table)
        apex_indexes = []
        for i in range(len(res_table)):
                if res_table[i] == max(res_table) :
                    apex_indexes.append(i)

        #print((apex_indexes))

        res = 0
        for i in range(len(apex_indexes)):
            #print("apex_indexes[i] = " + str(apex_indexes[i]))
            count1 = count_max_inc_len(s[:apex_indexes[i]+1])
            #print("count_max_inc_len(" + str(s[:apex_indexes[i]+1]) + ")=" + str(count1), end=" ")
            count2 = count_max_k_dec_len(s[apex_indexes[i]+1:],s[apex_indexes[i]]-1)
            #print("count_max_k_dec_len(" + str(s[apex_indexes[i]+1:])+ "," + str(s[apex_indexes[i]]-1) + ")=" + str(count2), end=" ")
            if count2 == 0 :
                res += count1
            else :
                res += count1 * count2
            #print(res)

        return res


def max_inc_len(s) :
    if len(s) == 0 :
        return 0

    tab = [1 for _ in range(len(s))]
    for i in range(1,len(s)) :
        for j in range(i) :
            if s[i] > s[j] and tab[j] + 1 > tab[i]:
                tab[i] = tab[j] + 1
    #print(tab)
    return max(tab)

def count_max_inc_len(s) :
    if len(s) == 0 :
        return 0

    tab = [1 for _ in range(len(s))]
    for i in range(1,len(s)) :
        for j in range(i) :
            if s[i] > s[j] and tab[j] + 1 > tab[i]:
                tab[i] = tab[j] + 1
    #print(tab)
    n_max = max(tab)
    if n_max > 0 :
        count = 0
        for i in range(len(tab)) :
            if tab[i] == n_max :
                count += 1
        return count
    else :
        return 0

def max_dec_len(s) :
    if len(s) == 0 :
        return 0

    tab = [1 for _ in range(len(s))]
    for i in range(1,len(s)) :
        for j in range(i) :
            if s[i] < s[j] and tab[j] + 1 > tab[i]:
                tab[i] = tab[j] + 1
    #print(tab)
    return max(tab)

def max_k_dec_len(s, k) :
    if len(s) == 0 :
        return 0

    tab = [0 for _ in range(len(s))]
    if s[0] <= k :
        tab[0] = 1

    for i in range(1,len(s)) :
        for j in range(i) :
            if s[j] <= k and s[i] < s[j] and tab[j] + 1 > tab[i]:
                tab[i] = tab[j] + 1
    #print(tab)
    return max(tab)

def count_max_k_dec_len(s, k) :
    if len(s) == 0 :
        return 0

    tab = [0 for _ in range(len(s))]
    if s[0] <= k :
        tab[0] = 1

    for i in range(1,len(s)) :
        for j in range(i) :
            if s[j] <= k and s[i] < s[j] and tab[j] + 1 > tab[i]:
                tab[i] = tab[j] + 1
    #print(tab)
    n_max = max(tab)
    if n_max > 0 :
        count = 0
        for i in range(len(tab)) :
            if tab[i] == n_max :
                count += 1
        return count
    else :
        return 0



def main() :
    s = [0, 9, 8, 5, 1, 8, 4, 7]
    #s = [1, 2, 1, 1, 2, 1]
    #s = [ 8, 5, 1, 8, 4, 7]
    #s = [3, 3, 3, 3, 3, 3 ]
    #print(A_seq_len(s))
    #print(max_dec_len(s))
    #print(max_k_dec_len(s,8))
    #print(count_max_k_dec_len(s,8))
    #print(max_inc_len(s))
    #print(A_seq_len(s))
    #print(count_A_seq_len(s))

    int_list = input()
    int_list = int_list.split(" ")
    goal = int(int_list[0])

    int_list = input()
    s = int_list.split(" ")
    for i in range(len(s)) :
        s[i] = int(s[i])

    if goal == 1 :
        print(A_seq_len(s))

    elif goal == 2 :
        print(count_A_seq_len(s))

    else :
        print("input error")
        

if __name__ == "__main__" :
    main()

