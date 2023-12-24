import sys

N = int(input())
table = [list(map(int, input().split())) for _ in range(N)]
diff = sys.maxsize
idf = [False for _ in range(N)]

def backtracking(depth, idx):
    global diff
    if depth == N//2:
        s_value = 0
        l_value = 0
        for i in range(N):
            for j in range(N):
                if idf[i] is True and idf[j] is True:
                    s_value += table[i][j]
                elif idf[i] is False and idf[j] is False:
                    l_value += table[i][j]
        
        diff = min(diff, abs(s_value - l_value))

    for i in range(idx, N):
        if not idf[i]:
            idf[i] = True
            backtracking(depth+1, i+1)
            idf[i] = False

backtracking(0, 0)
print(diff)
