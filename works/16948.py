from collections import deque

n = 0
r1 = 0; c1 = 0; r2 = 0; c2 = 0
mark = [[False for _ in range(201)] for _ in range(201)]
dr = [-2, -2, 0, 0, 2, 2]
dc = [-1, 1, -2, 2, -1, 1]

def bfs():
    q = deque()
    q.append([r1, c1, 0])
    while q:
        left = q.popleft()
        r = left[0]
        c = left[1]
        cnt = left[2]

        for i in range(6):
            nr = r + dr[i]
            nc = c + dc[i]
            if nr < 0 or nr >= n or nc < 0 or nc >= n: continue
            if mark[nr][nc]: continue
            if nr == r2 and nc == c2: return cnt+1
            mark[nr][nc] = True
            q.append([nr, nc, cnt+1])

    return -1


n = int(input())
r1, c1, r2, c2 = map(int, input().split())
print(bfs())