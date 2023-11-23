"""
    authored by jihwankim
    study
    23-11-23 PM 07:48 ~ 07:49
"""
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0 for i in range(n)]

def solve(k) :
    if(k == m) :
        for i in range(k):
            print(arr[i], end = " ")
        print()
        return
    for i in range(1, n+1) :
        arr[k] = i
        solve(k+1)

solve(0)