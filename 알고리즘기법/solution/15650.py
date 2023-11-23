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

"""
    N과 M (1)과 비교
    k가 1이었을 때, k+1은 2이상인 점
    k가 2라면, k+1은 3이상인 점
    이전 1을 방문 했다면 다시 1을 방문할 일이 없으므로 방문처리를 할 필요가 없다.
"""