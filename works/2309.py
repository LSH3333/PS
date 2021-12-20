arr = []
sum = 0
for i in range(9):
    arr.append(int(input()))
    sum = sum + arr[i]
sum = sum - 100

target1 = 0; target2 = 0
for i in range(9):
    for j in range(9):
        if arr[i] + arr[j] == sum:
            target1 = i; target2 = j
            break

ans = []
for i in range(9):
    if i==target1 or i==target2: continue
    ans.append(arr[i])

ans.sort()
for x in ans: print(x)

