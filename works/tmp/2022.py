import math

epsilon = 0.000001
x, y, c = map(float, input().split())

def Cal(mid):
    h1 = math.sqrt(x * x - mid * mid)
    h2 = math.sqrt(y * y - mid * mid)
    return (h1 * h2) / (h1 + h2)


low = 0.0
high = float(min(x, y))
result = 0.0

while high - low > epsilon:
    mid = (low + high) / 2.0
    if Cal(mid) >= c:
        result = mid
        low = mid
    else:
        high = mid

print(round(result,3))



