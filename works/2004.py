def Cal(n, div):
    cnt = 0
    while n>0:
        n //= div
        cnt += n
    return cnt


n, m = map(int, input().split())
a = Cal(n, 2) - (Cal(m,2) + Cal(n-m, 2))
b = Cal(n,5) - (Cal(m,5) + Cal(n-m,5))
print(min(a,b))
