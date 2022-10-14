a = int(input())
b = int(input())
c = int(input())
res = a * b * c
res_s = str(res)

mark = [0 for _ in range(10)]
for i in range(len(res_s)):
    mark[int(res_s[i])] += 1
    
for i in range(10):
    print(mark[i])