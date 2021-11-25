A, P = input().split()
A = int(A)
P = int(P)

def Cal(n):
    sum = 0
    while n > 0:
        sum += pow(n%10, P)
        n = n // 10

    return sum


cnt = 1
# dictionary
m = {}
m[A] = cnt
cnt += 1

while True:
    A = Cal(A)
    if A in m:
        print(m[A]-1)
        break
    m[A] = cnt
    cnt += 1

