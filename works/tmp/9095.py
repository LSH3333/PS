d = [0 for _ in range(11)]
d[0] = 0
d[1] = 1
d[2] = 2
d[3] = 4

for i in range(4, 11):
    d[i] = d[i-1] + d[i-2] + d[i-3]

t = int(input())
while t > 0:
    n = int(input())
    print(d[n])
    t -= 1
