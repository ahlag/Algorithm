import numpy as np

N, W = map(int, input().split())
dp = np.zeros(W+1, dtype=int)

print(dp)

for i in range(N):
    w, v = map(int, input().split())
    print(np.maximum(dp[w:],dp[:-w]+v))
    dp[w:] = np.maximum(dp[w:],dp[:-w]+v)
    
print(dp[-1])