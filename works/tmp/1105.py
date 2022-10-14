
n, m = input().split()
while len(n) != len(m):
    n = "0" + n

cnt = 0
_n = n; _m = m
for i in range(len(n)-1, -1, -1):
    if n[i] == '8' and m[i] == '8':
        l = list(n)
        l[i] = '9'
        n = "".join(l)
        if n > m: cnt += 1
        else:
            n = _n
            m = _m

print(cnt)