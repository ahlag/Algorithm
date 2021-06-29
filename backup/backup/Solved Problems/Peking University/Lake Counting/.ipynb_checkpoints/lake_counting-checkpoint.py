def dfs(i, j):
    
    if grid[i][j] == 'W':
        grid[i][j] = '.'
    else:
        return
        
    for dx in [-1, 0, 1]:
        for dy in [-1, 0, 1]:
            dfs(i + dx, j + dy)

n, m = map(int, input().split())

grid = [['.' for i in range(m+2)] for i in range(n+2)]

for i in range(n):
    s = input()
    for j in range(m):
        grid[i+1][j+1] = s[j]
        
print('Initial Grid')
print(grid)
        
cnt = 0
for i in range(1,n):
    for j in range(1,m):
        if grid[i][j] == 'W':
            cnt += 1
            dfs(i, j)

print('Ans')
print(grid)
print(cnt)