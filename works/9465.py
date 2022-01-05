from sys import stdin

t = int(input())
while t > 0:
    t -= 1
    n = int(stdin.readline())
    d = [[0 for _ in range(100010)] for _ in range(3)]
    a = []
    for _ in range(2):
        tmp = list(map(int, stdin.readline().split()))
        a.append(tmp)

    d[0][0] = a[0][0]
    d[1][0] = a[1][0]
    d[2][0] = max(a[0][0], a[1][0])

    if n > 1:
        d[0][1] = a[0][1] + d[1][0]
        d[1][1] = a[1][1] + d[0][0]
        d[2][1] = max(a[0][1], a[1][1])

    for i in range(2, n):
        d[0][i] = a[0][i] + max(d[1][i - 1], max(d[0][i - 2], max(d[1][i - 2], d[2][i - 2])))
        d[1][i] = a[1][i] + max(d[0][i - 1], max(d[0][i - 2], max(d[1][i - 2], d[2][i - 2])))
        d[2][i] = max(d[0][i - 2], max(d[1][i - 2], d[2][i - 2])) + max(a[0][i], a[1][i])

    print(max(d[0][n-1], max(d[1][n-1], d[2][n-1])))



