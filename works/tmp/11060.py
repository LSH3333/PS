from sys import stdin


def sol():
    n = int(input())
    a = list(map(int, stdin.readline().split()))
    d = [0 for _ in range(n + 1)]
    if n == 1: print(0); return 0

    d[0] = 0
    for i in range(1, n):
        lowest = 2000000000
        trigger = False
        for j in range(i):
            if j + a[j] >= i:
                lowest = min(lowest, d[j] + 1)
                trigger = True
        if not trigger: print(-1); return 0
        d[i] = lowest

    print(d[n-1])


sol()


