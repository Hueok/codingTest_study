N = int(input())
operands = list(map(int, input().split()))
operators = list(map(int, input().split()))

v_max = -10e9
v_min = 10e9

def solve(depth, rax):
    global v_max, v_min
    if depth == N:
        v_max = max(v_max, rax)
        v_min = min(v_min, rax)
        return
    
    if operators[0]:
        operators[0] -= 1
        solve(depth+1, rax+operands[depth])
        operators[0] += 1

    if operators[1]:
        operators[1] -= 1
        solve(depth+1, rax-operands[depth])
        operators[1] += 1

    if operators[2]:
        operators[2] -= 1
        solve(depth+1, rax*operands[depth])
        operators[2] += 1
        
    if operators[3]:
        operators[3] -= 1
        solve(depth+1, 0-(abs(rax)//abs(operands[depth])) if (rax<0 and operands[depth]>0) else rax//operands[depth])
        operators[3] += 1

solve(1,operands[0])
print(v_max)
print(v_min)