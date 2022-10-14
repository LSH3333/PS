MOD = 9901
n = int(input())
d = [[0 for _ in range(3)] for _ in range(n+1)]
d[1][0] = 1
d[1][1] = 1
d[1][2] = 1

for i in range(2, n+1):
    d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % MOD
    d[i][1] = (d[i - 1][0] + d[i - 1][2]) % MOD
    d[i][2] = (d[i - 1][0] + d[i - 1][1]) % MOD

print((d[n][0] + d[n][1] + d[n][2]) % MOD)
