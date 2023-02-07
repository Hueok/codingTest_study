#greedy algorithm
#Division N of K is prior choose
#Repeat devision if no rest. --> if rest is exist, repeat abtract 1. (all time of calculation, count += 1)

import sys

N, K = map(int, sys.stdin.readline().split())
count = 0

while N > 1:
    N = N//K if N%K == 0 else N - 1
    count += 1
print(count, N)