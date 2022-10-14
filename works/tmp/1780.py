

def Cal(n:int, r:int, c:int, arr, answer):
    num = arr[r][c]
    trigger = True
    for i in range(r, r+n):
        for j in range(c, c+n):
            if arr[i][j] != num:
                trigger = False; break

    if trigger:
        answer[num+1] += 1
        return

    for i in range(r, r+n, int(n/3)):
        for j in range(c, c+n, int(n/3)):
            Cal(int(n/3), i, j, arr, answer)


N = int(input())
arr = []
for i in range(N):
    tmp = list(map(int, input().split()))
    arr.append(tmp)

answer = [0, 0, 0]

Cal(N, 0, 0, arr, answer)

for x in answer: print(x)

