# N = 3
# v = [60, 100, 120]
# w = [10, 20, 30]
# # 最大の重さ
# W = 50

N = 6
W = 15
w = [6, 5, 6, 6, 3, 7]
v = [5, 6, 4, 6, 5, 2]

def knapsack(i, wt):

    if i >= N or wt + w[i] > W:
        return 0
    else:
        return max(knapsack(i+1, wt), knapsack(i+1, wt + w[i]) + v[i])

print(knapsack(0, 0))