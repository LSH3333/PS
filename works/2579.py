n = int(input())
score = [0 for _ in range(302)]
d = [[0 for j in range(2)] for i in range(302)]

for i in range(1, n+1):
    score[i] = int(input())

score[0] = 0
d[0][0] = 0
d[0][1] = 0
d[1][0] = score[1]
d[1][1] = score[1]

for i in range(2, n+1):
    d[i][0] = d[i-1][1] + score[i]
    d[i][1] = max(d[i-2][0], d[i-2][1]) + score[i]

print(max(d[n][0], d[n][1]))

