import sys 

arr = [[True for _ in range(1010)] for _ in range(1010)]
arr[0][0] = False

for i in range(1001):
    for j in range(1001):
        if i == 0 and j == 0: continue
        if not arr[i][j]: continue
        a = i; b = j
        while True:
            a += i; b += j
            if a > 1000 or b > 1000: break
            arr[a][b] = False

answer = [0 for _ in range(1010)]
cnt = 0
for i in range(1001):
    for a in range(i):
        cnt += arr[i][a]
        cnt += arr[a][i]
    cnt += arr[i][i]
    answer[i] = cnt

T = int(input())
while T > 0:
    N = int(input())
    print(answer[N])
    T -= 1
