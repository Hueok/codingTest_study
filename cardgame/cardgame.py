#greedy algorithm
#find minimum number in all of row --> make new array including all min --> pop largest num in that array.

import sys

N, M = map(int, sys.stdin.readline().split())
arr = [[x for x in map(int, sys.stdin.readline().split())] for i in range(N)]
min_arr = [min(x) for x in arr]

print(max(min_arr))