N, M = map(int, input().split())

if N <= 1:
    print(1)
elif N <= 2:
    if M >= 9: print(4)
    else: print((M-1) // 2 + 1)
elif M < 5:
    print(M)
elif M <= 5:
    print(M-1)
elif M > 5:
    print(M-2)
