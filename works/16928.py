from collections import deque
moveTo = [0 for _ in range(101)]
mark = [False for _ in range(101)]


def bfs():
    q = deque()
    q.append([1, 0])

    while q:
        left = q.popleft()
        cur = left[0]
        cnt = left[1]

        if cur == 100:
            return cnt

        for i in range(1, 7):
            ncur = cur + i
            if ncur > 100 or mark[ncur] == True: continue
            if moveTo[ncur] != 0:
                ncur = moveTo[ncur]
                mark[ncur] = True
                q.append([ncur, cnt+1])
            else:
                mark[ncur] = True
                q.append([ncur, cnt+1])


n, m = map(int, input().split())

for i in range(n+m):
    a, b = map(int, input().split())
    moveTo[a] = b

print(bfs())