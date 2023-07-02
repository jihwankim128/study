# 수 정렬3

import sys

n=int(sys.stdin.readline())
number=[0]*10001

for i in range(1,n+1):
    number[int(sys.stdin.readline())]+=1

for i in range(1,10001):
    for j in range(number[i]):
        #print(f"number {i}={number[i]}")
        sys.stdout.write(f"{i}"+'\n')
        #다 안 됐는데 stdout바꾸니까 바로 됨
