N = 0; M = 0
edge = []
for _ in range(1010): edge.append([])
mark = [False for _ in range(1010)]
cnt = 0


def dfs(v):
    if mark[v]: return
    mark[v] = True
    for x in edge[v]: dfs(x)


N, M = map(int, input().split())
for i in range(M):
    a, b = map(int, input().split())
    edge[a].append(b)
    edge[b].append(a)

for i in range(1, N+1):
    if mark[i]: continue
    dfs(i)
    cnt = cnt + 1

print(cnt)

