#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> e[1001];
bool check[1001];

int dfs(int v)
{
    if(check[v]) return 0;

    check[v] = true;
    // v에 연결된 간선은 1개
    // 루프 없이 하나의 간선만 타고 이동
    dfs(e[v][0]);

    return v;
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 1001; i++) e[i].clear();
        memset(check, false, sizeof(check));

        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int v; cin >> v;
            e[i].push_back(v);
        }

        int cycle = 0;
        for(int i = 1; i <= n; i++)
        {
            // 정점 i에서 발해서 dfs 탐색 결과가 자기 자신이면 하나의 사이클 완성 
            if(i == dfs(i)) cycle++;
        }

        cout << cycle << '\n';

    }
}