from itertools import permutations


def IsItMagicS(v):
    if v[0] + v[1] + v[2] != 15: return False
    if v[3] + v[4] + v[5] != 15: return False
    if v[6] + v[7] + v[8] != 15: return False

    if v[0] + v[3] + v[6] != 15: return False
    if v[1] + v[4] + v[7] != 15: return False
    if v[2] + v[5] + v[8] != 15: return False

    if v[0] + v[4] + v[8] != 15: return False
    if v[2] + v[4] + v[6] != 15: return False
    return True


answer = 99999
nums = []
for i in range(3):
    a, b, c = map(int, input().split())
    nums.append(a)
    nums.append(b)
    nums.append(c)

nums1 = list(range(1, 10))
per = list(permutations(nums1, len(nums1)))

for x in per:
    if IsItMagicS(x):
        sum = 0
        for i in range(9):
            sum += abs(nums[i] - x[i])
        answer = min(sum, answer)

print(answer)


