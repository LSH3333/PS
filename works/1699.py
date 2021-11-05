n = int(input())
d = [0 for _ in range(100001)]

d[0] = 0
d[1] = 1

for i in range(2, n+1):
    smallest = 100001
    num = 1

    while i - num**2 >= 0:
        smallest = min(smallest, d[i-num**2]+1)
        num += 1

    d[i] = smallest

print(d[n])
