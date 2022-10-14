#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int N, M;
vector<vector<int>> edge(101, vector<int>(0,0));
bool mark[101];

int bfs(int start)
{
    int sum = 0;
    queue<pair<int,int>> q;
    q.push({start, 0});
    mark[start] = true;

    while(!q.empty())
    {
        int nv = q.front().first;
        int depth = q.front().second;
        q.pop();
        sum += depth;

        for(int x : edge[nv])
        {
            if(mark[x]) continue;
            q.push({x, depth+1});
            mark[x] = true;
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int ans, smallest = 999999999;
    for(int i = 1; i <= N; i++)
    {
        int res = bfs(i);
        if(res < smallest)
        {
            smallest = res;
            ans = i;
        }
        memset(mark, false, sizeof(mark));
    }

    cout << ans;
}