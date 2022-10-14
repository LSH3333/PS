
def Draw(r, c, cnt, depth, stars, N):
    stars[r][c] = '*'

    for _ in range(cnt-1):
        r -= 1
        stars[r][c] = '*'

    for _ in range(cnt-1):
        c += 1
        if c >= len(stars[r]): break
        stars[r][c] = '*'

    if depth == N-1: return

    for _ in range(cnt+2-1):
        r += 1
        stars[r][c] = '*'

    for _ in range(cnt+2-1):
        c -= 1
        stars[r][c] = '*'

    Draw(r, c, cnt+4, depth+1, stars, N)


def Print(stars):
    for i in range(len(stars)):
        if i == 1:
            print('*', end='')
        else :
            for j in range(len(stars[i])):
                print(stars[i][j], end='')
        print()


N = int(input())
if N == 1: print('*')
else:
    stars = [[' ' for _ in range(4*N-4+1)] for _ in range(4*N-2+1)]
    Draw(2*N, 2*N-2, 3, 0, stars, N)
    Print(stars)