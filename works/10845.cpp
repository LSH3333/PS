#include <iostream>
#include <cstring>
#define MAX 10100
using namespace std;

// 원형 큐
class Queue
{
private:
    int arr[MAX];
    int f;
    int b;
    int nextPos(int i); // b의 다음지점 리턴

public:
    void Init();
    void push(int x);
    int pop();
    int size();
    bool empty();
    int front();
    int back();
};

int Queue::nextPos(int i)
{
    if(i+1 == MAX) return 0;
    else return i+1;
}

void Queue::Init()
{
    memset(arr, 0, MAX);
    f = 0;
    b = 0;
}

void Queue::push(int x)
{
    b = nextPos(b);
    arr[b] = x;
}

int Queue::pop()
{
    if(b == f) return -1;

    f = nextPos(f);
    return arr[f];
}

int Queue::size()
{
    if(f == b) return 0;
    else if(f < b) return b - f;
    else return (MAX-f-1) + (b-1);
}

bool Queue::empty()
{
    if(b == f) return true;
    else return false;
}

int Queue::front()
{
    if(f == b) return -1;
    return arr[nextPos(f)];
}

int Queue::back()
{
    if(f == b) return -1;
    return arr[b];
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    Queue queue{};
    queue.Init();

    int N; cin >> N;
    while(N--)
    {
        string op; cin >> op;
        if(op == "push")
        {
            int x; cin >> x;
            queue.push(x);
        }
        else if(op == "pop")
        {
            cout << queue.pop() << '\n';
        }
        else if(op == "size")
        {
            cout << queue.size() << '\n';
        }
        else if(op == "empty")
        {
            cout << queue.empty() << '\n';
        }
        else if(op == "front")
        {
            cout << queue.front() << '\n';
        }
        else if(op == "back")
        {
            cout << queue.back() << '\n';
        }
    }
}