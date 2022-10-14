from collections import deque


def bfs(n, k):
    mark = [[False for _ in range(200010)] for _ in range(2)]
    q = deque()
    q.append([0,0,0])

    while q:
        left = q.popleft()
        r = left[0]
        c = left[1]
        time = left[2]

        if c >= n: return True
        mark[r][c] = True

        if c+1 >= time+1 and c+1 >= n: return True
        if c+1 >= time+1 and arr[r][c+1] != '0' and mark[r][c+1] == False:
            mark[r][c+1] = True
            q.append([r, c+1, time+1])

        if c-1 >= time+1 and c-1 >= 0 and arr[r][c-1] != '0' and mark[r][c-1] == False:
            mark[r][c-1] = True
            q.append([r,c-1,time+1])

        nr = 1 if r == 0 else 0
        if c+k >= time+1 and c+k >= n: return True
        if c+k >= time+1 and arr[nr][c+k] != '0' and mark[nr][c+k] == False:
            mark[nr][c+k] = True
            q.append([nr, c+k, time+1])

    return False


n, k = map(int, input().split())
arr = []
s = input()
arr.append(s)
s = input()
arr.append(s)

ans = bfs(n, k)
if ans: print(1)
else: print(0)
