#include <iostream>
#include <vector>
#include <queue>
#define MAX 100010
using namespace std;

vector<vector<int>> edge(MAX, vector<int>(0,0));
//bool mark[MAX];
int answer[MAX];

void bfs()
{
    queue<int> q;
    q.push(1);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(auto x : edge[v])
        {
            if(answer[x] != 0) continue;
            answer[x] = v;
            q.push(x);
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