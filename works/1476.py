E, S, M = map(int, input().split())
cnt = 1
e = 1; s = 1; m = 1

while True:
    if (e == E) and (s == S) and (m == M): break
    cnt = cnt + 1

    e = e + 1 if e < 15 else 1
    s = s + 1 if s < 28 else 1
    m = m + 1 if m < 19 else 1

print(cnt)