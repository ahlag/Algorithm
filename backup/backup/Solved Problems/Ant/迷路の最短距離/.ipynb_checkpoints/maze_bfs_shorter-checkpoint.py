R, C = map(int, input().split())

cm = [[-1 for j in range(C)] for i in range(R)]

INF = float('inf')
## Has to start from 1 to avoid index out of range
for i in range(R):
    s = input()
    for j in range(1, C):
        if s[j-1] == '.':
            cm[i][j] =  INF
        if s[j-1] == 'S':
            sy, sx = i, j
            cm[i][j] =  0
        if s[j-1] == 'G':
            gy, gx = i, j
            cm[i][j] =  INF

queue = [[sy, sx]]

# 移動4方向のベクトル
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

while queue:
    
    y, x = queue.pop(0)
    
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
    
        if 0 <= nx < C and 0 <= ny < R:
            if cm[ny][nx] == INF:
                cm[ny][nx] = cm[y][x] + 1
                queue.append([ny, nx])
        
print(cm[gy][gx])