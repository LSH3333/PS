
v = []
for i in range(1, 13):
    if i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12:
        v.append([0 for _ in range(31)])
    elif i==4 or i==6 or i==9 or i==11:
        v.append([0 for _ in range(30)])
    else:
        v.append([0 for _ in range(28)])

n = 0
for i in range(len(v)):
    for j in range(len(v[i])):
        v[i][j] = n
        n = (n + 1) % 7

x, y = map(int,input().split())
day = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
print(day[v[x-1][y-1]])