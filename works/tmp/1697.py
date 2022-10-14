from collections import deque

N, K = map(int, input().split())
mark = [False for _ in range(100001)]
dv = [-1, 1, 2]

def bfs():
    q = deque()
    q.append([N, 0])
    mark[N] = True

    while q:
        tmp = q.popleft()
        v = tmp[0]
        depth = tmp[1]

        if v == K:
            return depth

        for i in range(3):
            nv = 0
            if i == 2: nv = v * dv[i]
            else: nv = v + dv[i]

            if (nv < 0) or (nv > 100000): continue
            if mark[nv]: continue
            q.append([nv, depth+1])
            mark[nv] = True


print(bfs())