#Last code(game.py) not considered prob's rule 3(if all side are sea, go backward). So, reset the code.
#implementation_simulation
#Exception Handling not implemented

import sys

N, M = map(int, sys.stdin.readline().split())
x, y, d = map(int, sys.stdin.readline().split())
maps = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

exper = [[0]*M for _ in range(N)] #Experienced Map
exper[x][y] = 1

#[North, East, South, West]
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

turn_time = 0
count = 1

def turn_left():
    global d 
    d -= 1
    if d == -1:
        d = 3

while True:
    turn_left()
    nx = x + dx[d]
    ny = y+ dy[d]

    if maps[nx][ny] == 0 and exper[nx][ny] == 0:
        x, y = nx, ny
        exper[x][y] = 1
        count += 1
        turn_time = 0
        continue
    else:
        turn_time += 1

    if turn_time == 4:
        nx = x - dx[d]
        ny = y - dy[d]
        
        if maps[nx][ny] == 0:
            x, y = nx, ny
            turn_time = 0
            continue
        else:
            break
print(count)