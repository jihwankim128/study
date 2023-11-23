"""
    authored by jihwankim
    study
    23-11-23 PM 07:22 ~ 07:40
"""
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
visited = [False for i in range(n+1)]
arr = [0 for i in range(n)]

def solve(k) :
    if(k == m) :
        for i in range(k):
            print(arr[i], end = " ")
        print()
    else:
        for i in range(1, n+1) :
            if not visited[i]:
                arr[k] = i
                visited[i] = True
                solve(k+1)
                visited[i] = False

solve(0)