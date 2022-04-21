class Stack:
    def __init__(self):
        self.arr = [0 for _ in range(10001)]
        self.ptr = -1

    def push(self, x):
        self.ptr+=1
        self.arr[self.ptr] = x

    def pop(self):
        if self.ptr == -1: return -1
        top = self.arr[self.ptr]
        self.ptr -= 1
        return top

    def size(self):
        return self.ptr+1

    def empty(self):
        if self.ptr == -1: return 1
        else: return 0

    def top(self):
        if self.ptr == -1: return -1
        return self.arr[self.ptr]


stack = Stack()
N = int(input())
answer = ""

for _ in range(N):
    _s = input().split()
    if _s[0] == "push":
        stack.push(int(_s[1]))

    elif _s[0] == "pop":
        answer += str(stack.pop()) + '\n'

    elif _s[0] == "size":
        answer += str(stack.size()) + '\n'

    elif _s[0] == "empty":
        answer += str(stack.empty()) + '\n'

    elif _s[0] == "top":
        answer += str(stack.top()) + '\n'


print(answer)