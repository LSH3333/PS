import math

MAX = 123456 * 2 + 10
primeNumber = [0 for _ in range(MAX)]

def FindPrimeNumbers():
    for i in range(2, MAX):
        primeNumber[i] = i

    for i in range(2, int(math.sqrt(MAX))):
        if primeNumber[i] == 0: continue
        for j in range(i*i, MAX, i):
            primeNumber[j] = 0


FindPrimeNumbers()
n = -1
while(True):
    n = int(input())
    if n == 0: break
    cnt = 0
    for i in range(n+1, 2*n+1):
        if primeNumber[i] != 0: cnt+=1
    print(cnt)