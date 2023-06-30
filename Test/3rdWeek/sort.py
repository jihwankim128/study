# 수 정렬3

import sys

n=int(input())
number=[0]*n

for i in range(1,n+1):
    number[int(sys.stdin.readline())]+=1

for i in range(1,n):
    for j in range(number[i]):
        #print(f"number {i}={number[i]}")
        print(i)
