finger = int(input())
num = int(input())
ans = 0
goAndReturn = 0

if finger == 1:
    goAndReturn = num - 1
    ans = 1 + (8 * goAndReturn)
    ans += 7

elif finger == 5:
    goAndReturn = num
    ans = 1 + (8 * goAndReturn)
    ans += 3

else:
    goAndReturn = num // 2
    ans = 1 + (8 * goAndReturn)
    if num % 2 == 0:
        ans += finger - 2
    else:
        ans += 7 - finger + 1

print(ans)