import itertools

N = int(input())
table = list()

for i in range(N):
    table.append(list(map(int, input().split())))

members = list(range(0, N))
cases = list(itertools.combinations(members, N//2))
diff = 10e8
for start_team in cases:
    link_team = [x for x in members if x not in start_team]
    s_value = 0
    l_value = 0
    for synergy in itertools.permutations(start_team, 2):
        s_value += table[synergy[0]][synergy[1]]
    for synergy in itertools.permutations(link_team, 2):
        l_value += table[synergy[0]][synergy[1]]
    diff = min(diff, abs(s_value - l_value))

print(diff)