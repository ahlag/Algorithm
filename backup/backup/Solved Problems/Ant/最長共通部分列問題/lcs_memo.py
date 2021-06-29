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

s = 'a'
t = 'z'

# Output = 0

n = len(s)
m = len(t)

def lcs(s, t, i, j, cache):
    
    if i >= n or j >= m:
        return 0
    
    if cache[i][j] is not None:
        return cache[i][j]
    
    if s[i] == t[j]:
        result = lcs(s, t, i+1, j+1, cache) + 1
    else:
        result = max(lcs(s, t, i+1, j, cache), lcs(s, t, i, j+1, cache))
    cache[i][j] = result
    
    return result

cache = [[None for i in range(m)] for j in range(n)]

print(lcs(s, t, 0, 0, cache))