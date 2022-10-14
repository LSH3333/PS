N, L = map(int, input().split())
a = map(int, input().split())
a = list(a)
a.sort()

end = a[0] - 0.5 + L
cnt = 1
for i in range(1, N):
    if a[i]+0.5 <= end: continue
    else:
        cnt += 1
        end = a[i] - 0.5 + L

print(cnt)
