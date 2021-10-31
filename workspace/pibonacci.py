import sys
sys.setrecursionlimit(100000)

d = [0 for _ in range(100000)]


def dp(n):
    # base check
    if n <= 1: return n
    # memoization
    if d[n] > 0: return d[n]
    # recurrence relation
    d[n] = dp(n-1) + dp(n-2)
    return d[n]


t = int(input())
for _ in range(t):
    n = int(input())
    print(dp(n))

