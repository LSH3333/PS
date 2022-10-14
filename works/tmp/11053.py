n = int(input())
answer = 1
v = list(map(int,input().split()))

d = [0 for _ in range(n+1)]
d[0] = 1
for i in range(1, n):
    highest = 0
    for j in range(i):
        if v[j] < v[i]:
            highest = max(highest, d[j])
        d[i] = highest + 1
        answer = max(answer, d[i])

print(answer)


