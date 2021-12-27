n = input()
sum = 0
isZero = False

for i in range(len(n)):
    if n[i] == '0': isZero = True
    sum += ord(n[i]) - ord('0')

if (sum % 3 == 0) and isZero:
    ans_str = ''.join(sorted(n, reverse=True))
    print(ans_str)
else:
    print(-1)