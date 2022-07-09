#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> edges[201];
bool mark[201];

void bfs(int start)
{
    mark[start] = true;
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(const auto &x : edges[cur])
        {
            if(mark[x]) continue;
            mark[x] = true;
            q.push(x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int n; cin >> n;
            if(n == 1) edges[i].push_back(j);
        }
    }
    vector<int> travel;
    for(int i = 0; i < M; i++) { int n; cin >> n; travel.push_back(n); }
    
    bfs(travel.front());

    for(const auto &x : travel)
    {
        if(!mark[x]) { cout << "NO"; return 0; }
    }
    cout << "YES";

}