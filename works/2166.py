
def CCW(x1, y1, x2, y2, x3, y3):
    a = x1*y2 + x2*y3 + x3*y1
    b = x2*y1 + x3*y2 + x1*y3

    return (a-b) / 2


n = int(input())
cord = [[0 for _ in range(2)] for _ in range(n+1)]
for i in range(n):
    a, b = map(int, input().split())
    cord[i][0] = a
    cord[i][1] = b

sum = 0.0
for i in range(1, n-1):
    sum += CCW(cord[0][0], cord[0][1], cord[i][0], cord[i][1], cord[i+1][0], cord[i+1][1])


print(round(abs(sum), 1))

