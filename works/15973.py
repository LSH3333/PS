left_x1, left_y1, right_x1, right_y1 = map(int, input().split())
left_x2, left_y2, right_x2, right_y2 = map(int, input().split())

if left_x1 > left_x2:
    temp_left_x = left_x2
    temp_left_y = left_y2
    temp_right_x = right_x2
    temp_right_y = right_y2

    left_x2 = left_x1
    left_y2 = left_y1
    right_x2 = right_x1
    right_y2 = right_y1

    left_x1 = temp_left_x
    left_y1 = temp_left_y
    right_x1 = temp_right_x
    right_y1 = temp_right_y

if right_x1 == left_x2:
    if right_y1 == left_y2 or left_y1 == right_y2: answer = "POINT"
    elif left_y2 > right_y1: answer = "NULL"
    elif left_y1 > right_y2: answer = "NULL"
    else: answer = 'LINE'

elif right_x1 > left_x2:
    if right_y1 == left_y2: answer = 'LINE'
    elif left_y1 == right_y2: answer = 'LINE'
    elif right_y1 < left_y2: answer = 'NULL'
    elif left_y1 > right_y2: answer = 'NULL'
    else: answer = 'FACE'

else:
    answer = 'NULL'

print(answer)
