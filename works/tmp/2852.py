N = int(input())
goal = []

def ChangeToSec(time):
    m = time[:2]
    s = time[3:]
    return int(m) * 60 + int(s)


def ChangeToMin(time):
    m = time // 60
    s = time % 60
    m_str = str(m)
    s_str = str(s)
    if len(m_str) == 1: m_str = "0" + m_str
    if len(s_str) == 1: s_str = "0" + s_str
    return m_str + ":" + s_str


for _ in range(N):
    _s = input().split(' ')
    team = int(_s[0])
    goal.append([team, ChangeToSec(_s[1])])

goal.append([0, 60*48])

t1 = 0; t2 = 0
v = []
for i in range(N):
    if goal[i][0] == 1: t1+=1
    else: t2+=1
    if t1 == t2: continue
    winning = 1 if t1 > t2 else 2
    v.append([goal[i][1], goal[i+1][1], winning])

t1Time = 0; t2Time = 0
for x in v:
    if x[2] == 1:
        t1Time += x[1] - x[0]
    else:
        t2Time += x[1] - x[0]

print(ChangeToMin(t1Time))
print(ChangeToMin(t2Time))