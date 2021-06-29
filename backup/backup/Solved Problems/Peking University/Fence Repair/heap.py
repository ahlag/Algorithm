import heapq

def solve(xs):
    ans = 0
    heapq.heapify(xs)
    while len(xs) > 1:
        x = heapq.heappop(xs) + heapq.heappop(xs)
        ans += x
        heapq.heappush(xs, x)
    return ans


N = 4
L = [5, 2, 1, 3]
print(solve(L))