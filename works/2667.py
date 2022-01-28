import sys
from collections import deque

arr = []
mark = [[0 for _ in range(30)] for _ in range(30)]
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
answer = []


def bfs(r, c, cnt):
    q = deque()
    mark[r][c] = cnt
    q.append([r,c])
    numberOfHouse = 1

    while q:
        left = q.popleft()
        nr = left[0]
        nc = left[1]

        for i in range(4):
            nnr = nr + dr[i]
            nnc = nc + dc[i]
            if nnr < 0 or nnr >= N or nnc < 0 or nnc >= N: continue
            if mark[nnr][nnc] > 0 or arr[nnr][nnc] == '0': continue
            mark[nnr][nnc] = cnt
            q.append([nnr,nnc])
            numberOfHouse += 1

    answer.append(numberOfHouse)


N = int(input())
for i in range(N):
    tmp = input()
    arr.append(tmp)

cnt = 1
for i in range(N):
    for j in range(N):
        if arr[i][j] == '1' and mark[i][j] == 0:
            bfs(i, j, cnt)
            cnt += 1

answer.sort()
print(cnt-1)
for x in answer: print(x)