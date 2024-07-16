#1:51
#implementation_simulation
#already visited space ~= sea
#searching direction : if start == north : west --> south --> east --> north

import sys

N, M = map(int, sys.stdin.readline().split())
x, y, d = map(int, sys.stdin.readline().split()) # x : from north; y : from west
directions = [0, 1, 2, 3]

maps = [list(x for x in map(int, sys.stdin.readline().split())) for i in range(N)]
print('Default setting successfully set')

maps[x][y] = 1
count = 1

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
r = 0 # while loop count
while True:
    r += 1
    nx = x + dx[directions[d-1]]
    ny = y + dy[directions[d-1]]

    if nx < 0 or nx > N-1 or ny < 0 or ny > M-1: #if nx or ny are out of maps
        d = directions[d-1]
        continue
    
    #Exception Handling
    if x == 0 and y == 0:
        if maps[x+dx[1]][y+dy[1]] and maps[x+dx[2]][y+dy[2]]:
            break
    elif x == 0 and y == M-1:
        if maps[x+dx[2]][y+dy[2]] and maps[x+dx[3]][y+dy[3]]:
            break
    elif x == N-1 and y == 0:
        if maps[x+dx[0]][y+dy[0]] and maps[x+dx[1]][y+dy[1]]:
            break
    elif x == N-1 and y == M-1 :
        if maps[x+dx[0]][y+dy[0]] and maps[x+dx[3]][y+dy[3]]:
            break
    elif x == 0:
        if maps[x+dx[1]][y+dy[1]] and maps[x+dx[2]][y+dy[2]] and maps[x+dx[3]][y+dy[3]]:
            break
    elif x == N-1:
        if maps[x+dx[0]][y+dy[0]] and maps[x+dx[1]][y+dy[1]] and maps[x+dx[3]][y+dy[3]]:
            break
    elif y == 0:
        if maps[x+dx[0]][y+dy[0]] and maps[x+dx[1]][y+dy[1]] and maps[x+dx[2]][y+dy[2]]:
            break
    elif y == M-1:
        if maps[x+dx[0]][y+dy[0]] and maps[x+dx[2]][y+dy[2]] and maps[x+dx[3]][y+dy[3]]:
            break
    
    if maps[nx][ny] == 1:
        d = directions[d-1]
        continue
    x, y = nx, ny
    maps[x][y] = 1
    d = directions[d-1]
    count += 1
    print(f'----------CURRENT MAPS[{r}]-------------\n')
    for row in maps:
        print(row)

print(count)



