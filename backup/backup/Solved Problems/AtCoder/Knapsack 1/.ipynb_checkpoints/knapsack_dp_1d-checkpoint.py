# N = 3
# v = [60, 100, 120]
# w = [10, 20, 30]
# # 最大の重さ
# W = 50

N = 6
W = 15
w = [6, 5, 6, 6, 3, 7]
v = [5, 6, 4, 6, 5, 2]

def knapsack():
    
    dp = [0 for i in range(W+1)]
    
    for i in range(N):
        print(dp)
        for wt in range(W):
            if wt + w[i] <= W:  
                dp[wt] = max(dp[wt], dp[wt+w[i]] + v[i])
                
    return dp[0]

# def knapsack():
    
#     dp = [0 for i in range(W+1)]
    
#     for i in range(N):
#         for wt in range(W, w[i]-1,-1):
#                 dp[wt] = max(dp[wt], dp[wt-w[i]] + v[i])
                
#     return dp[W]

print(knapsack())