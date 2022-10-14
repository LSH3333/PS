
def CCW(x1, y1, x2, y2, x3, y3):
    a = x1*y2 + x2*y3 + x3*y1
    b = x2*y1 + x3*y2 + x1*y3

    if a-b > 0: return 1
    return -1


x1,y1,x2,y2 = map(int, input().split())
x3,y3,x4,y4 = map(int, input().split())

abc = CCW(x1, y1, x2, y2, x3, y3)
abd = CCW(x1, y1, x2, y2, x4, y4)

dca = CCW(x4, y4, x3, y3, x1, y1)
dcb = CCW(x4, y4, x3, y3, x2, y2)

if abc * abd < 0 and dca * dcb < 0: print(1)
else: print(0)
