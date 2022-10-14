mark = []
edge = []


def dfs(n):
    if mark[n]: return
    mark[n] = True
    for x in edge[n]:
        dfs(x)


T = int(input())
while T:
    T -= 1
    N = int(input())
    edge = [[0 for _ in range(0)] for _ in range(N+1)]
    mark = [False for _ in range(1001)]
    cnt = 0
    v = input().split()
    v = list(map(int, v))
    for i in range(1, N+1):
        edge[i].append(v[i-1])
        edge[v[i-1]].append(i)

    for i in range(1, N+1):
        if mark[i]: continue
        dfs(i)
        cnt += 1

    print(cnt)

