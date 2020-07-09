"""
* user:  VR448339
* fname: FREGNAN
* lname: SEBASTIANO
* task:  gioco_cifre
* score: 100.0
* date:  2020-06-18 11:21:34.972979
"""
#!usr/bin/env python3
# -*- coding: utf-8 -*-


DEBUG = False

if __name__ == '__main__':
	
	if DEBUG:
		n = 16
	else:
		n = int(input().strip())
	
	move = n % 10
	if move != 0:
		print(1, move)
	else:
		print(0)
	
	exit(0)
