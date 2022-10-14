d = [0 for _ in range(50)]


def dp(n):
    if n <= 1:
        return n
    if d[n] > 0:
        return d[n]
    d[n] = dp(n-1) + dp(n-2)
    return d[n]


n = int(input())
print(dp(n))

