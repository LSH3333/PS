
limit = []
bottle = []
mark = [[[False for _ in range(210)] for _ in range(210)] for _ in range(210)]
answer = []


def dfs():
    if bottle[0] == 0: answer.append(bottle[2])

    for i in range(3):
        if bottle[i] == 0: continue

        for j in range(3):
            if i==j: continue
            if bottle[j] == limit[j]: continue
            toPour = limit[j] - bottle[j]
            i_before = bottle[i]
            j_before = bottle[j]

            if bottle[i] - toPour >= 0:
                bottle[i] -= toPour
                bottle[j] += toPour
            else:
                bottle[j] = bottle[i] + bottle[j]
                bottle[i] = 0

            if mark[bottle[0]][bottle[1]][bottle[2]]:
                bottle[i] = i_before
                bottle[j] = j_before
                continue

            mark[bottle[0]][bottle[1]][bottle[2]] = True
            dfs()
            mark[bottle[0]][bottle[1]][bottle[2]] = False
            bottle[i] = i_before
            bottle[j] = j_before


A, B, C = map(int, input().split())
limit.append(A); limit.append(B); limit.append(C)
bottle.append(0); bottle.append(0); bottle.append(C)
mark[0][0][C] = True
dfs()

answer.sort()
answer_unique = []
for i in answer:
    if i not in answer_unique:
        answer_unique.append(i)

for x in answer_unique: print(x, end=' ')

