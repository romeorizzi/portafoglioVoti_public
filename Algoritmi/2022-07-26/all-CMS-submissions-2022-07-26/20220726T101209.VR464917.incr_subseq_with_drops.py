"""
* user:  VR464917
* fname: GABRIELE
* lname: RONCOLATO
* task:  esameincr_subseq_with_drops
* score: 0.0
* date:  2022-07-26 10:12:09.681026
"""
results = {}


def calculate_max_seq(values, index, n, k):
    if index == n - 1:
        return 1
    elif int(values[index]) >= int(values[index + 1]) and k == 0:
        return 1
    elif results.get(f"{index} {k}") is not None:
        return results[f"{index} {k}"]
    elif int(values[index]) >= int(values[index + 1]) and k > 0:
        path1 = 1 + calculate_max_seq(values, index + 1, n, k - 1)
        path2 = 0 + calculate_max_seq(values, index + 1, n, k)
        results[f"{index + 1} {k - 1}"] = path1
        results[f"{index + 1} {k}"] = path2
        return max(path1, path2)
    else:
        return 1 + calculate_max_seq(values, index + 1, n, k)


def calculate_max_seq_num(values, index, n, k):
    if index == n - 1:
        return 1, 1, 1, 1
    elif int(values[index]) >= int(values[index + 1]) and k == 0:
        return 1, 1, 1, 1
    #elif results.get(f"{index} {k}") is not None:
    #    return results[f"{index} {k}"]
    elif int(values[index]) >= int(values[index + 1]) and k > 0:
        result1 = calculate_max_seq_num(values, index + 1, n, k - 1)
        path1 = 1 + result1[0]
        max_seq_count1 = result1[1]
        global_max_seq1 = result1[2]
        global_max_seq_count1 = result1[3]

        result2 = calculate_max_seq_num(values, index + 1, n, k)
        path2 = 0 + result2[0]
        max_seq_count2 = result2[1]
        global_max_seq2 = result2[2]
        global_max_seq_count2 = result2[3]

        if global_max_seq1 >= global_max_seq2:
            global_max_seq = global_max_seq1
            global_max_seq_count = global_max_seq_count1
        else:
            global_max_seq = global_max_seq2
            global_max_seq_count = global_max_seq_count2

        #results[f"{index + 1} {k - 1}"] = [path1, max_seq_count1]
        #results[f"{index + 1} {k}"] = [path2, max_seq_count2]

        if path1 == path2:
            seq = path1
            seq_count = max_seq_count1 + max_seq_count2
        elif path1 > path2:
            seq = path1
            seq_count = max_seq_count1
        else:
            seq = path2
            seq_count = max_seq_count2

        if seq > global_max_seq:
            global_max_seq = seq
            global_max_seq_count = seq_count
        elif seq == global_max_seq:
            global_max_seq_count += seq_count

        print(f"{seq_count}")
        return seq, seq_count, global_max_seq, global_max_seq_count
    else:
        result = calculate_max_seq_num(values, index + 1, n, k)
        path = 1 + result[0]
        max_seq_count = result[1]
        global_max_seq = result[2]
        global_max_seq_count = result[3]

        if path > global_max_seq:
            global_max_seq = path
            global_max_seq_count = 1
        elif path == global_max_seq:
            global_max_seq_count += 1

        return path, max_seq_count, global_max_seq, global_max_seq_count


parameters = input().split()
task_type = int(parameters[0])
seq_size = int(parameters[1])
fall_num = int(parameters[2])

seq = input().split()

if task_type == 0:
    result = calculate_max_seq(seq, 0, seq_size, fall_num)
else:
    result_total = calculate_max_seq_num(seq, 0, seq_size, fall_num)

print(f"{result}")