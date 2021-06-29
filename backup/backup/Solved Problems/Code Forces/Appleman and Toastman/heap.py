from heapq import heappop, heappush, heapify
N = int(input())
L = list(map(int,input().split()))

ans = sum(L)
s = ans

heapify(L)

while len(L) > 1:
    t = heappop(L)
    s -= t
    ans += t
    ans += s

print(ans)