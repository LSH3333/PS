t = int(input())
for _ in range(t):
    l = list(map(int, input().split()))
    n = l[0]
    avg = 0
    for i in range(1, len(l)): avg += l[i]
    avg /= n

    over = 0
    for i in range(1, len(l)):
        if l[i] > avg: over+=1

    answer = over / n
    answer *= 100
    answer = round(answer, 3)
    print(str('%.3f' % answer + '%'))