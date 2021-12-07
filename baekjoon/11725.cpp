#include <iostream>
#include <vector>
#include <queue>
#define MAX 100010
using namespace std;

vector<vector<int>> edge(MAX, vector<int>(0,0));
bool mark[MAX];
int answer[MAX];

void bfs()
{
    // from, vertex
    queue<pair<int,int>> q;
    q.push({1, 0});
    mark[1] = true;

    while(!q.empty())
    {
        int v = q.front().first;
        int from = q.front().second;
        q.pop();

        answer[v] = from;

        for(auto x : edge[v])
        {
            if(mark[x]) continue;
            mark[x] = true;
            q.push({x, v});
        }
    }
}

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 0; j < edge[i].size(); j++)
//        {
//            cout << edge[i][j] << ' ';
//        } cout << endl;
//    }

    bfs();

    for(int i = 2; i <= n; i++)
    {
        cout << answer[i] << '\n';
    }
}