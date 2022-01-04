n = int(input())
a = list(map(int, input().split()))
d = [0 for _ in range(n)]

d[0] = a[0]
answer = d[0]
for i in range(1, n):
    d[i] = max(d[i-1] + a[i], a[i])
    answer = max(answer, d[i])

print(answer)


