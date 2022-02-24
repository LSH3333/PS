x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())

a = x1*y2 + x2*y3 + x3*y1
b = x2*y1 + x3*y2 + x1*y3
cal = a - b

if cal == 0: print(0)
elif cal > 0: print(1)
else: print(-1)