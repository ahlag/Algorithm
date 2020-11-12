import sys
n, k = map(int, input().split())
h = list(map(int, input().split()))

dp = [sys.maxsize] * n
dp[0] = 0

for i in range(n):
    for j in range(i+1, i+k+1):
        if j < n:
            dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]))
            
print(dp[n-1])