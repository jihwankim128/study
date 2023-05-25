#잘못된 수 뒤에는 0이 나옴
#모든 정확한 수의 합을 출력
k=int(input())
stack=[]
for i in range(k):
    n=int(input())
    if n==0:
        stack.pop()
    else: stack.append(n)
    print(stack)
print(sum(stack))
    

