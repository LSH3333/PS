import sys

N, M = map(int, input().split())
trees = map(int, sys.stdin.readline().split())
trees = list(trees)

answer = 0
trees.sort()
left = 0; right = max(trees)

while left <= right:
    mid = (left + right) // 2

    sum = 0
    for i in range(N):
        if trees[i] > mid: sum += (trees[i] - mid)

    if sum < M:
        right = mid - 1
    else:
        left = mid + 1
        answer = mid

print(answer)

