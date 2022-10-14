def GetPos(n):
    len = 1
    val = n
    cnt = 0
    num = 1

    while val > 0:
        if val // 10 == 0:
            cnt += (n - len + 1) * num
            break
        else:
            cnt += 9 * len * num
            len *= 10
            num += 1
            val //= 10
    return cnt


def Sol():
    n, k = map(int, input().split())
    if n==9 and k==9:
        print(9)
        return 
    
    nPos = GetPos(n)   
    if k > nPos:
        print(-1)
        return

    cnt = 0
    num1 = 9
    num2 = 1
    res = 0
    while True:
        if res + num1 * num2 > k: break
        res += num1 * num2
        num1 *= 10
        num2 += 1
        cnt += 1

    cnt += 1
    if cnt == 0: pos = 1
    else: pos = pow(10, cnt-1)
    res += 1
    num = pos
    while True:
        if res > k: break
        num += 1
        res += cnt

    num-=1; res -= cnt
    num_s = str(num)
    answer = num_s[k-res]
    print(answer)


Sol()



