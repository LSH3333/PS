import sys
sys.setrecursionlimit(1000000)

dr = [1, 0, -1, 0]
dc = [0, 1, 0, -1]
N = int(input())
num = int(input())
ansR = 0; ansC = 0
v = [[0 for _ in range(N)] for _ in range(N)]


def dfs(r, c, cnt, dir):
    global ansR
    global ansC
    global v

    if cnt == 0: return
    if cnt == num:
        ansR = r
        ansC = c

    v[r][c] = cnt
    nr = r + dr[dir]
    nc = c + dc[dir]
    if nr < 0 or nr >= N or nc < 0 or nc >= N or v[nr][nc] != 0:
        dir = (dir + 1) % 4
        nr = r + dr[dir]
        nc = c + dc[dir]

    return dfs(nr, nc, cnt-1, dir)



dfs(0, 0, N*N, 0)

for i in range(N):
    for j in range(N):
        print(v[i][j], end=' ')
    print()
print(ansR+1, ansC+1)

