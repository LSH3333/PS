nums = [0 for _ in range(10)]
number = input()
for i in range(len(number)):
    nums[int(number[i])]+=1

a = 0; b = 0
for i in range(10):
    if i == 6 or i == 9: continue
    a = max(a, nums[i])
b = nums[6] + nums[9]
if b % 2 != 0: b = b // 2 + 1
else: b = b // 2
print(max(a,b))
