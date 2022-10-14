dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]
w = 0
h = 0
arr = []
mark = []


def dfs(r, c):
    if mark[r][c]: return

    mark[r][c] = True
    for i in range(0, 8):
        nr = r + dr[i]
        nc = c + dc[i]
        if (nr < 0) | (nr >= h) | (nc < 0) | (nc >= w): continue
        if arr[nr][nc] != 1: continue
        dfs(nr, nc)


while True:
    ans = 0
    w, h = map(int, input().split())
    if (w == 0) & (h == 0): break;

    arr = [[0 for _ in range(w)] for _ in range(h)]
    mark = [[False for _ in range(w)] for _ in range(h)]

    for i in range(h):
        arr[i] = list(map(int, input().split()))

    for i in range(h):
        for j in range(w):
            if (arr[i][j] != 1) | (mark[i][j]): continue
            dfs(i, j)
            ans += 1

    print(ans)


