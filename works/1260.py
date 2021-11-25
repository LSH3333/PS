edge = [[0 for _ in range(0)] for _ in range(10001)]
mark = [0 for _ in range(1001)]
N, M, V = map(int, input().split())


def dfs(n):
    if mark[n]: return
    print(n, end=' ')
    mark[n] = True
    for x in edge[n]: dfs(x)


def bfs(n):
    q = []
    q.append(n)
    mark[n] = True

    while q:
        v = q[0]
        print(v, end=' ')
        q.pop(0)

        for x in edge[v]:
            if mark[x]: continue
            q.append(x)
            mark[x] = True

for i in range(0, M):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

for i in range(1, N+1):
    edge[i].sort()

dfs(V)
print()
mark = [0 for _ in range(1001)]
bfs(V)