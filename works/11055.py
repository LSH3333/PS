from sys import stdin

n = int(input())
a = list(map(int, stdin.readline().split()))
d = [0 for _ in range(n+1)]

d[0] = a[0]
answer = d[0]
for i in range(1,n):
    highest = 0
    for j in range(i):
        if a[j] < a[i]: highest = max(highest, d[j])
    d[i] = highest + a[i]
    answer = max(answer, d[i])

print(answer)