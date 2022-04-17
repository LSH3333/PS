#include <iostream>
#include <cstring>
#define MAX 10001
using namespace std;

class Stack
{
private:
    int arr[MAX];
    int ptr;

public:
    void Init();
    void push(int x);
    int pop();
    int size();
    bool empty();
    int top();
};

void Stack::Init()
{
    memset(arr, 0, MAX);
    ptr = -1;
}

void Stack::push(int x)
{
    arr[++ptr] = x;
}

int Stack::pop()
{
    if(ptr == -1) return -1;
    int top = arr[ptr--];
    return top;
}

int Stack::size()
{
    return ptr+1;
}

bool Stack::empty()
{
    if(ptr == -1) return true;
    else return false;
}

int Stack::top()
{
    if(ptr == -1) return -1;
    return arr[ptr];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    Stack stack{};
    stack.Init();

    int N; cin >> N;
    while(N--)
    {
        string op; cin >> op;
        if(op == "push")
        {
            int x; cin >> x;
            stack.push(x);
        }
        else if(op == "pop")
        {
            cout << stack.pop() << '\n';
        }
        else if(op == "size")
        {
            cout << stack.size() << '\n';
        }
        else if(op == "empty")
        {
            cout << stack.empty() << '\n';
        }
        else if(op == "top")
        {
            cout << stack.top() << '\n';
        }
    }
}