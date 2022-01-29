import sys


class Node:
    def __init__(self, root, left, right):
        self.root = root
        self.left = left
        self.right = right


pre = []
inorder = []
post = []
map = {}


def PreOrder(root):
    if root == '.': return
    pre.append(root)
    PreOrder(map[root].left)
    PreOrder(map[root].right)


def PostOrder(root):
    if root == '.': return
    PostOrder(map[root].left)
    PostOrder(map[root].right)
    post.append(root)


def InOrder(root):
    if root == '.': return
    InOrder(map[root].left)
    inorder.append(root)
    InOrder(map[root].right)


n = int(input())
for i in range(0,n):
    _s = input()
    map[_s[0]] = Node(_s[0], _s[2], _s[4])

PreOrder('A')
PostOrder('A')
InOrder('A')

for x in pre: print(x, end='')
print()
for x in inorder: print(x, end='')
print()
for x in post: print(x, end='')


