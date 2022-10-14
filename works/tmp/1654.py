import sys

len = [0 for _ in range(10001)]

K, N = map(int, input().split())
left = 0; right = 0
for i in range(K):
    num = int(input())
    len[i] = num
    right += len[i]

answer = 0
while left <= right:
    mid = (left + right) // 2
    if mid == 0: mid+=1

    cnt = 0
    for i in range(0, K): cnt += (len[i] // mid)

    if cnt < N:
        right = mid - 1
    else:
        left = mid + 1
        answer = max(mid, answer)

print(answer)