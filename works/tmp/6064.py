t = int(input())
while t:
    t -= 1
    M, N, x, y = map(int, input().split())

    if M < N:
        big = N; bigVal = y; small = M; smallVal = x
    else:
        big = M; bigVal = x; small = N; smallVal = y

    temp = smallVal
    sub = big - small
    cnt = 0
    found = False

    while True:
        if temp == bigVal: found = True; break
        if temp - sub <= 0:
            subTmp = temp - sub
            temp = big - (subTmp * -1)

        else: temp -= sub
        if temp == smallVal: break
        cnt += 1

    if not found: print(-1)
    else: print((small*cnt) + smallVal)