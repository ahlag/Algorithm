# s = 'abcd'
# t = 'becd'
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

n = len(s)
m = len(t)

def lcs(s, t, i, j):
    
    if i >= n or j >= m:
        return 0
    
    if s[i] == t[j]:
        result = lcs(s, t, i+1, j+1) + 1
    else:
        result = max(lcs(s, t, i+1, j), lcs(s, t, i, j+1))
        
    return result

print(lcs(s, t, 0, 0))