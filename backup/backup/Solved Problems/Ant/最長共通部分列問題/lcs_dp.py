s = 'abcd'
t = 'becd'
# Output = 3

# s = 'ABCBDAB'
# t = 'BDCABA'

# Output = 4

# s = 'axyb'
# t = 'abyxb'

# Output = 3

# s = 'aa'
# t = 'xayaz'

# Output = 2

# s = 'a'
# t = 'z'

# Output = 0

def lcs(s, t):
    
    n = len(s)
    m = len(t)
    
    dp = [[0 for i in range(m+1)] for j in range(n+1)]
    
    for i in range(n):
        for j in range(m):
            if s[i] == t[j]:
                dp[i+1][j+1] = dp[i][j] + 1
            else:
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
        
            
    return dp[n][m]

print(lcs(s, t))