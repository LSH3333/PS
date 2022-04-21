import sys

N = int(input())
maxVal = 0
arr = map(int, sys.stdin.readline().split())
arr = list(arr)

for x in arr:
    if x > maxVal: maxVal = x
M = int(input())

left = 0; right = maxVal; answer = 0
while left <= right:
    mid = (left + right) // 2
    
    _sum = 0
    for i in range(N):
        if arr[i] > mid: _sum += mid
        else: _sum += arr[i]

    if _sum <= M:
        left = mid + 1
        answer = mid
    else:
        right = mid - 1

print(answer)

