MAX = 1000010
p = [0 for _ in range(MAX)]


def FindPrime():
    global p
    for i in range(2, MAX):
        p[i] = i

    d = int(MAX ** 0.5)
    for i in range(2, d):
        if p[i] == 0: continue
        for j in range(i*i, MAX, i):

            p[j] = 0


FindPrime()
n, m = map(int, input().split())
for i in range(n, m+1):
    if p[i] == 0: continue
    print(p[i])

