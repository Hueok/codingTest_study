N, S = map(int, input().split())
stack = list(map(int, input().split()))
rcx=0

def backTrack(depth, idx, limit):
    global rax, rcx
    if depth == limit:
        if rax == S:
            rcx +=1
        return

    for i in range(idx, N):
        rax += stack[i]
        backTrack(depth+1, i+1, limit)
        rax -= stack[i]

for i in range(1,N+1):
    rax= 0 
    backTrack(0, 0, i)

print(rcx)

