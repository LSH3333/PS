import sys

mark = [False for _ in range(2000010)]
students = [False for _ in range(2000010)]
n, c = map(int, input().split())
cnt = 0

for i in range(0, n):
    num = int(sys.stdin.readline())
    if students[num]: continue
    students[num] = True
    for j in range(num, c+1, num):
        if not mark[j]:
            cnt += 1
            mark[j] = True

print(cnt)