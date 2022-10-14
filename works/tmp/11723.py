import sys

S = [False for _ in range(21)]
m = int(input())

while m > 0:
    m -= 1
    order = sys.stdin.readline().rstrip()
    idx = order.find(' ')
    op = ''
    num = 0
    if idx != -1:
        op = order[:idx]
        num = int(order[idx+1:])
    else:
        op = order
    if op == 'add':
        S[num] = True
    elif op == 'remove':
        S[num] = False
    elif op == 'check':
        ans = 1 if S[num] else 0
        print(ans)
    elif op == 'toggle':
        S[num] = not S[num]
    elif op == 'all':
        S = [True for _ in range(21)]
    elif op == 'empty':
        S = [False for _ in range(21)]
