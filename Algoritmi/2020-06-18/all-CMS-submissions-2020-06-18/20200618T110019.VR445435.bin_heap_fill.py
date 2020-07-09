"""
* user:  VR445435
* fname: ZEGGIOTTI
* lname: MATTEO
* task:  bin_heap_fill
* score: 0.0
* date:  2020-06-18 11:00:19.159421
"""
#!/usr/bin/env python3

import sys

file = sys.stdin
l = 0
command = 0
heap = []
e_buono = []
f = []

line = file.readline()
first = line.split(" ")
l = int(first[0])
command = int(first[1].rstrip())
heap = file.readline().rstrip().split(" ")
e_buono = file.readline().rstrip().split(" ")
f = file.readline().rstrip().split(" ")

heap = list(map(int, heap))
e_buono = list(map(int, e_buono))
f = list(map(int, e_buono))


def verify_heap_property(heap, e):
    error_index = []
    for i in range(1, len(heap)):
        if heap[i] >= heap[(i - 1) // 2]:  # figlio >= papa'
            if e[i] == 0:
                error_index.append(i)
        else:
            if e[i] == 1:
                error_index.append(i)
    return len(error_index) == 0, error_index


result, errors = verify_heap_property(heap, e_buono)

def f_find(heap, indexes):
    combinations = []
    elements = []
    for i in indexes:
        elements.append(heap[i])
    elements.sort()
    combinations.append(elements)
    e_good = [0]
    for i in range(1, len(heap)):
        e_good.append(1)
    ok, _ = verify_heap_property(heap, e_good)
    return ok

if command == 1:
    if(verify_heap_property(heap, e_buono)):
        print("1")
    else:
        print("0")
else:
    index_array = []
    i = 0
    for f_el in f:
        if f_el == 0:
            index_array.append(i)
        i = i + 1
    if (f_find(heap, index_array)):
        print("1")
    else:
        print("0")

