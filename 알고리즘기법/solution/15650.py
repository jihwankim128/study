"""
    authored by jihwankim
    study
    23-11-23 PM 07:40 ~ 07:46
"""
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [0 for i in range(n)]

def solve(k, idx) :
    if(k == m) :
        for i in range(k):
            print(arr[i], end = " ")
        print()
        return
    for i in range(idx, n+1) :
        arr[k] = i
        solve(k+1, i+1)

solve(0, 1)