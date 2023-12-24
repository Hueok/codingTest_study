n = int(input())

operands = list(map(int, input().split()))
operators = list(map(int, input().split()))

maxValue = -10e9 
minValue = 10e9 #will changed

def dfs(depth, rax):
    global maxValue, minValue
    if depth == n-1:
        maxValue = max(maxValue, rax)
        minValue = min(minValue, rax)
    
    if operators[0]:
        operators[0] -= 1
        dfs(depth+1, rax+operands[depth+1])
        operators[0] += 1

    if operators[1]:
        operators[1] -= 1
        dfs(depth+1, rax-operands[depth+1])
        operators[1] += 1
        
    if operators[2]:
        operators[2] -= 1
        dfs(depth+1, rax*operands[depth+1])
        operators[2] += 1
    
    if operators[3]:
        operators[3] -= 1
        dfs(depth+1, 0-(abs(rax) // abs(operands[depth+1])) if (rax < 0 and operands[depth+1]>0) or (rax>0 and operands[depth+1]<0) else rax//operands[depth+1])
        operators[3] += 1

dfs(0, operands[0])
print(maxValue)
print(minValue)