"""
    authored by jihwankim
    study
    23-11-23 PM 07:49 ~ 07:50
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
        solve(k+1, i)

solve(0, 1)

"""
    N과 M 2에서 같은 원소를 1번 더 방문하는 차이
"""