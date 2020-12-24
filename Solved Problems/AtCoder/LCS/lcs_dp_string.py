s1 = input()
s2 = input()

n = len(s1)
m = len(s2)

dp = [ ['' for i in range(m+1)] for i in range(n+1) ]

for i in range(1,n+1):
    for j in range(1,m+1):
        if s1[i-1] == s2[j-1]:
            dp[i][j] = dp[i-1][j-1] + s1[i-1]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1], key=len)
                
print(dp[n][m])