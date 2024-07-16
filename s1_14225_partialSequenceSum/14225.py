N = int(input())
stack = list(map(int, input().split()))
visited = [False for _ in range(sum(stack)+2)]

def solve(depth, rax):

    if depth >= N:
        return
    
    rax += stack[depth]
    visited[rax] = True

    solve(depth+1, rax)
    solve(depth+1, rax-stack[depth])

solve(0,0)
print(visited[1:].index(0)+1)