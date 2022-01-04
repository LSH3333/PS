d = [[[0 for _ in range(51)] for _ in range(51)] for _ in range(51)]


def w(a, b, c):
    if(a <= 0) or (b <= 0) or (c <= 0): return 1
    if(a > 20) or (b > 20) or (c > 20): return d[20][20][20]

    if d[a][b][c] > 0: return d[a][b][c]
    if (a < b) and (b < c):
        d[a][b][c-1] = w(a,b,c-1)
        d[a][b-1][c-1] = w(a,b-1,c-1)
        d[a][b-1][c] = w(a,b-1,c)
        return d[a][b][c-1] + d[a][b-1][c-1] - d[a][b-1][c]

    d[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1)
    return d[a][b][c]


d[0][0][0] = 1
d[20][20][20] = 1048576

while True:
    a, b, c = map(int, input().split())
    if (a == -1) and (b == -1) and (c == -1): break
    ans = w(a, b, c)
    answer = "w("
    answer += str(a)
    answer += ", "
    answer += str(b)
    answer += ", "
    answer += str(c)
    answer += ") = "
    answer += str(ans)
    print(answer)
