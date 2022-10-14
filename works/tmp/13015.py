N = int(input())
w = 4 * N - 3
h = 2 * N - 1
mid = w - N * 2
board = [[] for _ in range(h)]

# 첫 줄
for i in range(N): board[0].append('*')
for i in range(mid): board[0].append(' ')
for i in range(N): board[0].append('*')
mid -= 2

l = 0
for i in range(1, N):
    for j in range(0, i): board[i].append(' ')
    board[i].append('*')
    for j in range(N-2): board[i].append(' ')
    board[i].append('*')
    for j in range(mid): board[i].append(' ')
    if mid > 0: board[i].append('*')
    mid-=2
    for j in range(N-2): board[i].append(' ')
    board[i].append('*')
    l = i-1
mid = 1

for i in range(N, h-1):
    for j in range(l): board[i].append(' ')
    l-=1
    board[i].append('*')
    for j in range(N-2): board[i].append(' ')
    board[i].append('*')
    for j in range(mid): board[i].append(' ')
    mid += 2
    board[i].append('*')
    for j in range(N-2): board[i].append(' ')
    board[i].append('*')

for i in range(N): board[h-1].append('*')
for i in range(mid): board[h-1].append(' ')
for i in range(N): board[h-1].append('*')

for i in range(h):
    for x in board[i]: print(x, end='')
    print()