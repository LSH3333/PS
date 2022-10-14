def GCD(a, b):
    if b == 0: return a
    return GCD(b, a%b)


gcd, lcm = map(int, input().split())
lcm = lcm / gcd
i = 0
a = 0
b = 0
while True:
    i += 1
    if i * i > lcm: break

    if lcm % i != 0: continue
    a_tmp = i
    b_tmp = lcm / i

    if GCD(a_tmp, b_tmp) == 1:
        a = a_tmp
        b = b_tmp

print(int(a*gcd), int(b*gcd))

