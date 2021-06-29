import heapq

# it is the min heap implementation
nums = [4, 7, 3, -2, 1, 0]
heap = []

for value in nums:
    heapq.heappush(heap, value)

while heap:
    print(heapq.heappop(heap))





