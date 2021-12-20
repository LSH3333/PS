str = input()
sum = 0
# 파이썬의 삼항연산자
sum = 10 if str[0] == 'd' else 26

for i in range(1, len(str)):
    if str[i] == str[i-1]:
        if str[i] == 'd': sum = sum * 9
        else: sum = sum * 25
    else:
        if str[i] == 'd': sum = sum * 10
        else: sum = sum * 26

print(sum)