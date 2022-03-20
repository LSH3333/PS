n, m = map(int, input().split())
v = list(map(int,input().split()))
ans = 0; ansSub = 99999999

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            sum = v[i] + v[j] + v[k]
            if sum <= m and m-sum < ansSub:
                ansSub = m - sum
                ans = sum

print(ans)

