arr = []
N = int(input())
for _ in range(N):
    n = int(input())
    arr.append(n)

answer = 0
for i in range(N-2, -1, -1):
    if arr[i] >= arr[i+1]:
        sub = arr[i] - arr[i+1] + 1
        answer += sub
        arr[i] -= sub

print(answer)
