import sys

sys.setrecursionlimit(10**6)  # 최대 재귀 깊이 변경

n, r, c = map(int, sys.stdin.readline().split())

def z(m, x, y):
    if m == 1:
        return 0
    
    half = m // 2
    q = half * half
    
    if x < half and y < half: #제 1사분면
        return z(half, x, y)
    elif x < half and y >= half: #제 2사분면
        return q + z(half, x, y - half)
    elif x >= half and y < half: #제 3사분면
        return q * 2 + z(half, x - half, y)
    else: #제 4사분면
        return q * 3 + z(half, x - half, y - half)

print(z(2**n, r, c))