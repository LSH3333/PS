from sys import stdin

n = int(input())
a = list(map(int, stdin.readline().split()))
d = [0 for _ in range(n + 1)]

d[0] = 1
answer = 1
for i in range(1, n):
    highest = 1
    for j in range(i):
        if a[j] > a[i]: highest = max(highest, d[j]+1)
    d[i] = highest
    answer = max(answer, d[i])

print(answer)