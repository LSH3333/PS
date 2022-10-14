from collections import deque

N, M = map(int, input().split())
answer = 0
#arr = [[0 for _ in range(N)] for _ in range(M)]
#arr = [[] for _ in range(N)]
arr = [list(map(int, input().split())) for _ in range(N)]
mark = [[0 for _ in range(M)] for _ in range(N)]
dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]

def bfs(r, c):
    global answer
    q = deque()
    q.append([r,c])
    mark[r][c] = 1

    while q:
        tmp = q.popleft()
        nr = tmp[0]
        nc = tmp[1]

        if arr[nr][nc] == 1:
            if mark[nr][nc]-1 > answer: answer = mark[nr][nc]-1
            break

        for i in range(8):
            nnr = nr + dr[i]
            nnc = nc + dc[i]

            if (nnr<0) | (nnr>=N) | (nnc<0) | (nnc>=M): continue
            if mark[nnr][nnc] != 0: continue
            q.append([nnr,nnc])
            mark[nnr][nnc] = mark[nr][nc] + 1
    return


for i in range(N):
    for j in range(M):
        if arr[i][j] == 1: continue
        bfs(i, j)
        mark = [[0 for _ in range(M)] for _ in range(N)]

print(answer)
