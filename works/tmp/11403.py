
def dfs(i, v, mark, canVisit):
    for x in v[i]:
        if mark[x]: continue
        mark[x] = True
        canVisit.append(x)
        dfs(x, v, mark, canVisit)


n = int(input())
ans = [[0 for _ in range(110)] for _ in range(110)]

v = [[0 for _ in range(0)] for _ in range(n)]
for i in range(n):
    _s = input().split()
    for j in range(n):
        if _s[j] == '1': v[i].append(j)


for i in range(n):
    mark = [False for _ in range(n)]
    canVisit = []
    dfs(i, v, mark, canVisit)
    for j in canVisit: ans[i][j] = 1

for i in range(n):
    for j in range(n):
        print(ans[i][j], end=' ')
    print()



