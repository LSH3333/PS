import sys
MAX = 10100


class Queue:
    def __init__(self):
        self.arr = [0 for _ in range(MAX)]
        self.f = 0
        self.b = 0

    def nextPos(self, i):
        if i+1 == MAX: return 0
        else: return i+1

    def push(self, x):
        self.b = self.nextPos(self.b)
        self.arr[self.b] = x

    def pop(self):
        if self.b == self.f: return -1
        self.f = self.nextPos(self.f)
        return self.arr[self.f]

    def size(self):
        if self.f == self.b: return 0
        elif self.f < self.b: return self.b-self.f
        else: return (MAX-self.f-1)+(self.b-1)

    def empty(self):
        if self.b == self.f: return 1
        else: return 0

    def front(self):
        if self.f == self.b: return -1
        return self.arr[self.nextPos(self.f)]

    def back(self):
        if self.f == self.b: return -1
        return self.arr[self.b]


queue = Queue()
N = int(input())
answer = ""

for _ in range(N):
    _s = sys.stdin.readline().split()
    if _s[0] == "push":
        queue.push(int(_s[1]))

    elif _s[0] == "pop":
        answer += str(queue.pop()) + '\n'

    elif _s[0] == "size":
        answer += str(queue.size()) + '\n'

    elif _s[0] == "empty":
        answer += str(queue.empty()) + '\n'

    elif _s[0] == "front":
        answer += str(queue.front()) + '\n'

    elif _s[0] == "back":
        answer += str(queue.back()) + '\n'

print(answer)



