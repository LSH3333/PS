import sys
from collections import deque

arr = []
mark = [[False for _ in range(110)] for _ in range(110)]
dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]
answer = 2000000000


def bfs():
    global answer
    q = deque()
    mark[0][0] = True
    # r,c,depth
    q.append([0,0,1])

    while q:
        left = q.popleft()
        r = left[0]
        c = left[1]
        depth = left[2]

        if (r == n-1) and (c == m-1):
            answer = min(answer, depth)
            continue

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr < 0 or nr >= n or nc < 0 or nc >= m: continue
            if mark[nr][nc] or arr[nr][nc] == '0': continue
            mark[nr][nc] = True
            q.append([nr,nc,depth+1])


n, m = map(int, input().split())
for i in range(n):
    str = input()
    arr.append(str)

bfs()

print(answer)