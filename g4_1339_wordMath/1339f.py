N = int(input())
data = list()

for i in range(N):
    data.append(input())

rdi =''.join(data)
rdi = [x for x in rdi]
rdi = list(set(rdi))
length = len(rdi)
#tmp = [None] * length

visited = [False]*10
result = []

isOne = True
for i in range(N):
    if len(data[i]) > 1:
        isOne = False


def dfs(depth, tmp):
    if depth == length:
        result.append(tmp)
        return
    for i in range(9,9-length,-1):
        if visited[i]:
            continue

        visited[i] = True
        dfs(depth+1, tmp+str(i))
        visited[i] = False

if isOne:
    calc = sum(range(N))
    print(calc)
else:
    dfs(0, '')
    print(len(result))

    calc = list()
    for rsi in result:
        rdata=list()
        for i in range(N):
            rdata.append([rsi[rdi.index(x)] for x in data[i]])
            rdata[i]=list(map(str, rdata[i]))
            rdata[i]=''.join(rdata[i])
            rdata[i]=int(rdata[i])
        calc.append(sum(rdata))
    print(max(calc))


    
