R, C = map(int, input().split())

cm = [[-1 for j in range(C+2)] for i in range(R+2)]

INF = float('inf')
## Has to start from 1 to avoid index out of range
for i in range(1, R+1):
    s = input()
    for j in range(1, C+1):
        if s[j-1] == '.':
            cm[i][j] =  INF
        if s[j-1] == 'S':
            sy, sx = i, j
            cm[i][j] =  0
        if s[j-1] == 'G':
            gy, gx = i, j
            cm[i][j] =  INF

queue = [sy, sx]

print(cm)

while queue:
    y = queue.pop(0)
    x = queue.pop(0)
    if cm[y][x+1] == INF:
        cm[y][x+1] = cm[y][x] + 1
        queue.append(y)
        queue.append(x+1)
    if cm[y+1][x] == INF:
        cm[y+1][x] = cm[y][x] + 1
        queue.append(y+1)
        queue.append(x)
    if cm[y][x-1] == INF:
        cm[y][x-1] = cm[y][x] + 1
        queue.append(y)
        queue.append(x-1)
    if cm[y-1][x] == INF:
        cm[y-1][x] = cm[y][x] + 1
        queue.append(y-1)
        queue.append(x)
        
print(cm[gy][gx])