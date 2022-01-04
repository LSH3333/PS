d = [0 for _ in range(1010)]
d[1] = 1
d[2] = 2

for i in range(1, 1001):
    sum = 0
    for j in range(1, i//2+1):
        sum += d[j]
    d[i] = sum + 1

t = int(input())
while(t > 0):
    t -= 1
    n = int(input())
    print(d[n])