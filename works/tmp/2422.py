N, M = map(int, input().split())
v = []
mark = [False for _ in range(201)]
bad = [[False for _ in range(201)] for _ in range(201)]
global ans
ans = 0

def IsPossible():
    for i in range(3):
        for j in range(3):
            if i == j: continue
            if bad[v[i]][v[j]]: return False
    return True


def dfs(idx, depth):
    global ans
    if depth == 3:
        if IsPossible(): ans = ans + 1
        return

    for i in range(idx, N+1):
        if mark[i]: continue
        mark[i] = True
        v.append(i)
        dfs(i, depth+1)
        mark[i] = False
        v.pop()


for _ in range(M):
    a, b = map(int, input().split())
    bad[a][b] = True
    bad[b][a] = True

dfs(1, 0)

print(ans)


