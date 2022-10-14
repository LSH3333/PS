#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
int ans[110][110];

void dfs(int i, vector<vector<int>> &v ,vector<bool> &mark, vector<int> &canVisit)
{
    for(auto x : v[i])
    {
        if(mark[x]) continue;
        mark[x] = true;
        canVisit.push_back(x);
        dfs(x, v, mark, canVisit);
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vector<vector<int>> v(n, vector<int>(0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int num; cin >> num;
            if(num == 1) v[i].push_back(j);
        }
    }
//
//    for(auto x : v)
//    {
//        for(auto y : x) cout << y << ' ';
//        cout << endl;
//    } cout << endl << endl;

    for(int i = 0; i < n; i++)
    {
        vector<bool> mark(n, false);
        vector<int> canVisit;
        dfs(i, v, mark, canVisit);
        for(auto j : canVisit) ans[i][j] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        } cout << '\n';
    }
}