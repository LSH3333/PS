depth = 0

def Hanoi(num, fro, by, to, l:list):
    global depth
    depth += 1
    if num == 1:
        l.append([fro, to])
        return

    Hanoi(num-1, fro, to, by, l)
    l.append([fro, to])
    Hanoi(num-1, by, fro, to, l)


n = int(input())
l = []
Hanoi(n, 1, 2, 3, l)
print(depth)
for x in l: print(x[0], x[1])