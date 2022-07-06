"""
* user:  VR472361
* fname: ELIA
* lname: PERANTONI
* task:  A_seq
* score: 0.0
* date:  2022-06-29 09:50:37.455569
"""
g, n = [int(word) for word in input().split()]
nums = [int(word) for word in input().split()]
assert(len(nums) == n)

def when_peak_at(i):
    c = 1

    # <<<-
    at = nums[i]
    for j in range(i-1, -1, -1):
        if nums[j] < at:
            at = nums[j]
            c += 1

    # ->>>
    at = nums[i]
    for j in range(i+1, n):
        if nums[j] < at:
            at = nums[j]
            c += 1

    return c

c = max(when_peak_at(i) for i in range(n))

if g == 1:
    print(c)
else:
    how_many = 0

    for i in range(n):
        for a in range(0, c):
            a_orig = a

            b = c - 1 - a

            # <<<-
            at = nums[i]
            j = i-1
            while a > 0 and j >= 0:
                if nums[j] < at:
                    at = nums[j]
                    a -= 1
                j -= 1

            # ->>>
            at = nums[i]
            j = i+1
            while b > 0 and j < n:
                if nums[j] < at:
                    at = nums[j]
                    b -= 1
                j += 1

            if a == 0 and b == 0:
                print("Peak", i, "A", a_orig)
                how_many += 1

    print(how_many)
