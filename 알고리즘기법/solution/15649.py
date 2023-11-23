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

"""
    길이가 m인 수열 -> 종료조건 : 재귀 depth == m
    중복 없이 -> 이전에 방문한 원소는 방문하지 않음.
    사전순 -> 오름차순 -> 1 to n
    재귀 depth가 k번째 일 때, 어떤 원소를 방문했는지 저장하는 배열추가
    -> 방문 후에 k번째는 다음 원소로 바뀔테니 방문처리를 없앰.
    재귀 depth == m이 되면 k번째까지 저장된 모든 원소를 출력하고 종료
"""