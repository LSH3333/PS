d = [0 for _ in range(102)]
d[0] = 0
d[1] = 1
d[2] = 1
d[3] = 1

for i in range(4, 101):
    d[i] = d[i-2] + d[i-3]

t = int(input())
while t > 0:
    n = int(input())
    print(d[n])
    t -= 1

