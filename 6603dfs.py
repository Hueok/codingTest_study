result = list()

def dfs(depth:int, idx:int):

    if depth == 6:
        print(*result)
        return
    
    for i in range(idx, k):
        result.append(s[i])
        dfs(depth+1, i+1)
        result.pop()

while True:
    query = list(input().split())
    s = query[1:]
    k = int(query[0])
    if k==0:
        break
    dfs(0, 0)
    print()