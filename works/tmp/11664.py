class Point:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z


def CalDistance(a:Point, b:Point):
    return (pow((a.x-b.x), 2) + pow((a.y-b.y),2) + pow((a.z-b.z),2)) ** (1/2)


Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz = map(float, input().split())
zero = Point(0.0, 0.0, 0.0)
a = Point(Ax, Ay, Az)
b = Point(Bx, By, Bz)
c = Point(Cx, Cy, Cz)



minDistance = CalDistance(zero, Point(10000, 10000, 10000))
t = 1000000
while t > 0:
    t -= 1
    mid = Point((a.x+b.x)/2, (a.y+b.y)/2, (a.z+b.z)/2)
    dis = CalDistance(mid, c)
    if dis < minDistance: minDistance = dis

    # print(a.x, a.y, a.z)
    # print(b.x, b.y, b.z)

    acDis = CalDistance(a, c)
    bcDis = CalDistance(b, c)

    if acDis <= bcDis:
        b = mid
    else:
        a = mid

print(minDistance)



