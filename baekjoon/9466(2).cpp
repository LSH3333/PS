#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int edges[100010];
int c[100010];
int s[100010];
int res = 0;

void dfs(int node, int cnt, int step)
{
    if(c[node] > 0)
    {
        if(s[node] == step) res += cnt - c[node];
        return;
    }
    c[node] = cnt;
    s[node] = step;
    dfs(edges[node], cnt+1, step);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        memset(c, 0, sizeof(c));
        memset(s, 0, sizeof(s));
        memset(edges, 0, sizeof(edges));
        res = 0;
        cin >> N;
        for(int i = 1; i <= N; i++)
        {
            cin >> edges[i];
        }

        int step = 0;
        for(int i = 1; i <= N; i++)
        {
            if(c[i] != 0) continue;
            step++;
            dfs(i, 1, step);
        }
        cout << N - res << '\n';
    }


}