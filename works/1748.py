n = int(input())
num = 1
cnt = 0
while num <= n:
    cnt += (n - num + 1)
    num *= 10
print(cnt)