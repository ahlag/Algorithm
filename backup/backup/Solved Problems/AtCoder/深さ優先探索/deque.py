from collections import deque
h, w = map(int, input().split())

cm = [[0 for j in range(w+2)] for i in range(h+2)]

for i in range(1, h+1):
    s = input()
    for j in range(1, w+1):
        if s[j-1] == '.':
            cm[i][j] = -1
        if s[j-1] == 's':
            cm[i][j] == 0
            sy, sx = i, j 
        if s[j-1] == 'g':
            cm[i][j] = -1
            gy, gx = i, j
    
queue = deque()
queue.append([sy, sx])

while queue:
    y, x = queue.pop()

    cm[y][x] = 0

    if cm[y][x+1] == -1:
        queue.append([y, x+1])
    if cm[y+1][x] == -1:
        queue.append([y+1, x])
    if cm[y][x-1] == -1:
        queue.append([y, x-1])
    if cm[y-1][x] == -1:
        queue.append([y-1, x])
        
if cm[gy][gx] == 0:
    print('Yes')
else:
    print('No')
