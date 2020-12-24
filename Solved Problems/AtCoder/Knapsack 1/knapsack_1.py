N, W = map(int, input().split())

weight = [0] * N
value  = [0] * N

for i in range(0, N):
    a, b = map(int, input().split())
    weight[i] = a
    value[i] = b

dp = [ [0] * (W+1) for i in range(N+1) ]

for i in range(0, N):
    for j in range(0, W+1):
        if j < weight[i]:
            dp[i+1][j] = dp[i][j]
        else:
            dp[i+1][j] = max(value[i] + dp[i][j- weight[i]], dp[i][j])
            
print(dp[N][W])