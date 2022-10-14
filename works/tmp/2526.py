a, b = map(int, input().split())
m = {}
num = a
cnt = 1

while True:
    if m.get(num) is not None:
        print(len(m) - (m[num]-1))
        break

    m[num] = cnt
    cnt += 1
    num = num * a % b