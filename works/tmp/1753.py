from queue import PriorityQueue
import sys
# 파이썬 우선순위큐는 디폴트가 오름차순


def Dijkstra(d, graph, start):
    d[start] = 0
    pq = PriorityQueue()
    pq.put([0, start])

    while not pq.empty():
        top = pq.get()
        distance = top[0]
        cur = top[1]

        if d[cur] < distance: continue

        for i in range(0, len(graph[cur])):
            next = graph[cur][i][0]
            nextDistance = distance + graph[cur][i][1]

            if nextDistance < d[next]:
                d[next] = nextDistance
                pq.put([nextDistance, next])



V, E = map(int, input().split())
start = int(input())
graph = [[] for _ in range(V+1)]
for i in range(E):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append([b,c])

d = [2000000000 for _ in range(V+1)]
Dijkstra(d, graph, start)

for i in range(1, V+1):
    if d[i] == 2000000000: print("INF")
    else: print(d[i])

