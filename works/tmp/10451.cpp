#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000
using namespace std;

int T, N;

bool mark[MAX+1];

void dfs(int n, vector<vector<int>> &edge)
{
    if(mark[n]) return;

    mark[n] = true;
    for(auto x : edge[n]) dfs(x, edge);
}

int main()
{
    cin >> T;
    while(T--)
    {
        vector<vector<int>> edge(MAX+1, vector<int>(0,0));
        cin >> N;
        int cnt = 0;
        for(int i = 1; i <= N; i++)
        {
            int v; cin >> v;
            edge[i].push_back(v);
            edge[v].push_back(i);
        }

        for(int i = 1; i <= N; i++)
        {
            if(mark[i]) continue;
            dfs(i, edge);
            cnt++;
        }
        cout << cnt << '\n';
        fill_n(mark, sizeof(mark), false);
    }

}