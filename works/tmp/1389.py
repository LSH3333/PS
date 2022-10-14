from collections import deque

N, M = map(int, input().split())
edge = [[] for _ in range(N+1)]
mark = [False for _ in range(101)]


def bfs(start):
    sum = 0
    q = deque()
    q.append([start, 0])
    mark[start] = True

    while q:
        tmp = q.popleft()
        nv = tmp[0]
        depth = tmp[1]
        sum = sum + depth

        for x in edge[nv]:
            if mark[x]: continue
            q.append([x, depth+1])
            mark[x] = True

    return sum


for i in range(M):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

ans = 999999999; smallest = 999999999
for i in range(1, N+1):
    res = bfs(i)
    if res < smallest:
        smallest = res
        ans = i
    mark = [False for _ in range(101)]

print(ans)
