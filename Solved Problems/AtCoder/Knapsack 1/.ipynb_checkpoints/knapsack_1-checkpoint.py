n, m = map(int, input().split())

weight = []
value = []
for _ in range(n):
    a, b = map(int, input().split())
    weight.append(a)
    value.append(b)
    
dp = [ [0] * (m+1) for i in range(n+1) ]
for i in range(1, n+1):
    for w in range(1, m+1):
        if j < weight[w]:
            dp[i][w] = value[i]
        elif w >= weight[i]:
            dp[i][w] = max(value[i] + dp[i-1][w-weight[i]], dp[i-1][w])
            
print(dp[n-1][w])