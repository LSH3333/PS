R, C = input().split()
R = int(R)
C = int(C)
arr = [list(input()) for _ in range(R)]

trigger = False
for i in range(0, R):
    if trigger: break
    for j in range(0, C):
        if arr[i][j] != 'W': continue
        flag = False

        if i-1 >= 0:
            if arr[i-1][j] == 'S': flag = True
        if j+1 < C:
            if arr[i][j+1] == 'S': flag = True
        if i+1 < R:
            if arr[i+1][j] == 'S': flag = True
        if j-1 >= 0:
            if arr[i][j-1] == 'S': flag = True

        if flag:
            print(0)
            trigger = True
            break


if trigger == False:
    print(1)
    for i in range(0, R):
        for j in range(0, C):
            if arr[i][j] == '.':
                print('D', end='')
            else:
                print(arr[i][j], end='')
        print()
