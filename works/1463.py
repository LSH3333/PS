d = [0 for _ in range(1000001)]

n = int(input())
d[0] = 0
d[1] = 0

for i in range(2, n + 1):
    num = d[i - 1] + 1
    if i % 2 == 0:
        num = min(num, d[int(i / 2)] + 1)
    if i % 3 == 0:
        num = min(num, d[int(i / 3)] + 1)
    d[i] = num


print(d[n])

