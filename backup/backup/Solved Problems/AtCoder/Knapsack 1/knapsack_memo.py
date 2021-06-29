# N = 3
# v = [60, 100, 120]
# w = [10, 20, 30]
# # 最大の重さ
# W = 50

N = 6
W = 15
w = [6, 5, 6, 6, 3, 7]
v = [5, 6, 4, 6, 5, 2]

dp = [[None for i in range(W+1) ] for j in range(N+1)]

def knapsack(i, wt):
    
    if dp[i][wt] is not None:
        return dp[i][wt]

    if i >= N or wt + w[i] > W:
        res = 0
    else:
        res = max(knapsack(i+1, wt), knapsack(i+1, wt + w[i]) + v[i])
    
    dp[i][wt] = res
    return res

print(knapsack(0, 0))