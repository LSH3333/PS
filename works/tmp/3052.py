v = [0 for _ in range(10)]

for i in range(10):
    v[i] = int(input())
    v[i] %= 42

v = set(v)
print(len(v))
