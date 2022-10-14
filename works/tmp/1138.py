from itertools import permutations

N = int(input())
order = map(int, input().split())
order = list(order)

line = []
for i in range(1, N+1): line.append(i)

# line = list(permutations(line, len(line)))
line = permutations(line, len(line))

for l in line:
    isAnswer = True

    for i in range(0, N):
        cur = l[i]
        taller = order[cur-1]
        cnt = 0

        for j in range(0, i):
            if l[j] > l[i]: cnt+=1

        if cnt != taller:
            isAnswer = False
            break

    if isAnswer:
        for i in range(0, N): print(l[i], end=' ')
        break

