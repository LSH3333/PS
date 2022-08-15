#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

int N, K;
int mark[100010];

void bfs()
{
    queue<pair<int,int>> q;
    mark[N] = 0;
    q.push({N, 0});

    while(!q.empty())
    {
        int cur = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(cur == K) return;

        if(cur+1 <= MAX && mark[cur+1] > sec+1)
        {
            mark[cur+1] = sec+1;
            q.push({cur+1, sec+1});
        }
        if(cur-1 >= 0 && mark[cur-1] > sec+1)
        {
            mark[cur-1] = sec+1;
            q.push({cur-1, sec+1});
        }
        if(cur*2 <= MAX && mark[cur*2] > sec)
        {
            mark[cur*2] = sec;
            q.push({cur*2, sec});
        }
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 0; i <= MAX; i++) mark[i] = MAX;
    bfs();
    cout << mark[K];
}