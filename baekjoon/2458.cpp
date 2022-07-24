#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int bfs(int start, const vector<int> edge[])
{
    vector<bool> mark(N+1, false);
    queue<int> q;
    q.push(start);
    mark[start] = true;

    int cnt = -1;
    while(!q.empty())
    {
        int cur = q.front();
        cnt++;
        q.pop();

        for(auto x : edge[cur])
        {
            if(mark[x]) continue;
            mark[x] = true;
            q.push(x);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<int> taller[510];  // [i] = {a,b} : i번 학생보다 큰 a,b 학생
    vector<int> smaller[510];
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        taller[a].push_back(b);
        smaller[b].push_back(a);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++)
    {
        int sum = 0;
        sum += bfs(i, taller);
        sum += bfs(i, smaller);
        if(sum == N-1) answer++;
    }
    cout << answer;
}