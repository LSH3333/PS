import math
import sys

MAX = 1000001
primeNumber = [0 for _ in range(MAX)]

def FindPrimeNumbers():
    for i in range(2, MAX):
        primeNumber[i] = i

    for i in range(2, int(math.sqrt(MAX))):
        if primeNumber[i] == 0: continue
        for j in range(i*i, MAX, i):
            primeNumber[j] = 0


FindPrimeNumbers()

while True:
    n = int(sys.stdin.readline())
    if n == 0: break
    a = -1; b = -1
    for i in range(1, n, 2):
        if primeNumber[i] != 0 and primeNumber[n-i] != 0:
            a = i
            b = n - i
            break

    if a == -1 and b == -1: print("Goldbach's conjecture is wrong.")
    else: print(n, '=', a, '+', b)