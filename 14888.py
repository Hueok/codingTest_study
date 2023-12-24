import itertools

N = int(input())
operands = list(map(int, input().split()))
operators_num = list(map(int, input().split()))
operators = ['+']*operators_num[0] + ['-']*operators_num[1] + ['*']*operators_num[2] + ['/']*operators_num[3]

ops_func = {
    '+': lambda x,y: x+y,
    '-': lambda x,y: x-y,
    '*': lambda x,y: x*y,
    '/': lambda x,y: 0-(abs(x) // abs(y)) if (x<0 and y>0) or (x>0 and y<0) else x//y
}

cases = list(itertools.permutations(operators, N-1))

result = []
for case in cases:
    rax = operands[0]
    for i in range(len(case)):
        rax = ops_func[case[i]](rax, operands[i+1])
    result.append(rax)
        
result.sort(reverse = True)
print(result[0])
print(result[-1])
