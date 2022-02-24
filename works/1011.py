import sys
sys.setrecursionlimit(1000000)

def dfs(distance, moved, cnt):
    if distance == 0: return cnt

    for move in range(moved+1, moved-2, -1):
        if move <= 0: continue
        sum = (move * (move + 1)) / 2
        if sum <= distance:
            return dfs(distance-move, move, cnt+1)


t = int(input())
while t:
    t -= 1
    x,y = map(int, input().split())
    distance = y - x
    ans = dfs(distance, 0, 0)
    print(ans)