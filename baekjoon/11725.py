import sys
# dequeue가 queue보다 훨씬 빠르다? 
from collections import deque

n = int(input())
edge = [[] for _ in range(n+1)]
answer = [0 for _ in range(n+1)]


def bfs():
    q = deque()
    q.append(1)

    while q:
        v = q.popleft()

        for x in edge[v]:
            if answer[x] != 0: continue
            answer[x] = v
            q.append(x)


for i in range(0, n-1):
    a, b = map(int, sys.stdin.readline().split())
    edge[a].append(b)
    edge[b].append(a)

bfs()

for i in range(2, n+1):
    print(answer[i])


