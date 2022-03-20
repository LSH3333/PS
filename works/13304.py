arr = [[0 for _ in range(2)] for _ in range(7)]

N, K = map(int, input().split())
for i in range(N):
    gender, grade = map(int,input().split())
    arr[grade][gender] += 1

v = []
v.append(arr[1][0] + arr[1][1] + arr[2][0] + arr[2][1])
v.append(arr[3][0] + arr[4][0])
v.append(arr[3][1] + arr[4][1])
v.append(arr[5][0] + arr[6][0])
v.append(arr[5][1] + arr[6][1])

ans = 0
for x in v:
    ans += x // K
    if x % K != 0: ans += 1

print(ans)