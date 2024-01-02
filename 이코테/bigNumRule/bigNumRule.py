#greedy algorithm
#sort --> K loop last index: sum += list[last index]
# --> use one last-1 index and count++ --> if count == M: break --> return sum

import sys
import time

N, M, K = map(int, sys.stdin.readline().split())
arr = [x for x in map(int, sys.stdin.readline().split())]
arr.sort()

first = arr[-1]
second = arr[-2]

result = 0

while True:
    for i in range(K):
        if M == 0:
            break
        result += first
        M -= 1
    if M == 0 :
        break
    result += second
    M -= 1

print(result)