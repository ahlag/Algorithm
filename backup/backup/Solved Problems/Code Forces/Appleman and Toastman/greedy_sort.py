from collections import deque

N = int(input())
L = list(map(int,input().split()))

L.sort()
ans = sum(L)

for i in range(N-1):
    ans += L[i]
    ans += sum(L[i+1:])
    
print(ans)