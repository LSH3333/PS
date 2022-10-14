n = list(input())
n.sort(reverse=True)
sum = sum(map(int,n))

if n[len(n)-1] == '0' and sum % 3 == 0:
    print(''.join(n))
else:
    print(-1)

