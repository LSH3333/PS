import sys
from collections import deque

M, N = map(int, input().split())
arr = [[0 for _ in range(1010)] for _ in range(1010)]
mark = [[0 for _ in range(M+1)] for _ in range(N+1)]
location = []
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
numOfZero = 0
answer = 0
for i in range(N):
    arr[i] = list(map(int, input().split()))

for i in range(N):
    for j in range(M):
        if arr[i][j] == 1: location.append([i, j])
        if arr[i][j] == -1: mark[i][j] = -1
        if arr[i][j] == 0: numOfZero += 1


def bfs():
    global answer
    q = deque()
    for x in location:
        q.append([x[0], x[1], 1])
        mark[x[0]][x[1]] = 1

    while q:
        left = q.popleft()
        r = left[0]
        c = left[1]
        depth = left[2]

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr < 0 or nr >= N or nc < 0 or nc >= M: continue
            if arr[nr][nc] == -1 or mark[nr][nc] > 0: continue
            mark[nr][nc] = depth + 1
            q.append([nr, nc, depth + 1])
            answer = max(answer, depth + 1)


isZero = False
if numOfZero == 0: isZero = True
bfs()
success = True
for i in range(N):
    for j in range(M):
        if mark[i][j] == 0:
            success = False
            break


if isZero:
    print(0)
elif not success:
    print(-1)
else:
    print(answer - 1)
