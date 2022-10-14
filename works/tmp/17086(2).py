from queue import Queue

q = Queue()
d = [[0 for _ in range(51)] for _ in range(51)]
add = [[False for _ in range(51)] for _ in range (51)]
l = [[0 for _ in range(51)] for _ in range(51)]
w = 0; h = 0

dr = [-1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 1, 1, 1, 0, -1, -1, -1]


def Print():
    for i in range(h):
        print(l[i])
    print()

def bfs():
    while q.empty() == False:
        f = q.get()
        for i in range(8):
            nr = f[0] + dr[i]
            nc = f[1] + dc[i]
            if (0 <= nr < h) and (0 <= nc < w):
                if not add[nr][nc]:
                    q.put([nr, nc])
                    add[nr][nc] = True
                    l[nr][nc] = l[f[0]][f[1]] + 1


h, w = map(int, input().split())
for r in range(h):
    d[r] = list(map(int, input().split()))
    for c in range(w):
        if d[r][c] == 1:
            q.put([r,c])
            add[r][c] = True
            l[r][c] = 0

bfs()

max = 0
for r in range(h):
    for c in range(w):
        if max < l[r][c]: max = l[r][c]

print(max)