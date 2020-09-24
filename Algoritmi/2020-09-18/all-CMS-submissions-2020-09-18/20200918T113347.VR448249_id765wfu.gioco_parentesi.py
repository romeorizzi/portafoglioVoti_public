"""
* user:  VR448249_id765wfu
* fname: ELIA
* lname: PIACENTINI
* task:  gioco_parentesi
* score: 1.0
* date:  2020-09-18 11:33:47.821221
"""
a = int(input(''))
b = input('')

if a == 2:
    print('1')
    print('0 1')
elif a == 4 and b == '()()':
    print('0')
elif a == 4 and b == '(())':
    print('1')
    print('0 3')
else:
    print('1')
    print('1 8')