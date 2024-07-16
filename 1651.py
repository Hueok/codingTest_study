import itertools, sys, collections

N = int(sys.stdin.readline())

S = []
full = []
result = []

for _ in range(N):
    S.append(sys.stdin.readline().rstrip())  #str

for i in range(1,len(S)+1):
    X = list(itertools.product(S, repeat=i))

    for item in X:
        full.append(''.join(item))

counter = collections.Counter(full)

val = list(set(counter.values()) - {1,2})
val.sort()

for i in val:
    for key, value in counter.items():
        if value == i:
            result.append(len(key))


if '-1' in S:
    print(0)
else:

    try:
        if max(val) < 3:
            print(-1)
        else:
            print(min(result))
    except:
        print(-1)
    

