#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
bool mark[201];
int answer = 0;
bool bad[201][201];

bool IsPossible(vector<int> &comb)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j) continue;
            if(bad[comb[i]][comb[j]]) return false;
        }
    }
    return true;
}

void dfs(int idx, int depth)
{
    if(depth == 3)
    {
        vector<int> comb;
        for(int i = 0; i < N; i++)
            if(mark[i]) comb.push_back(v[i]);
//        for(auto x : comb) cout << x << ' '; cout << endl;
        if(IsPossible(comb)) answer++;
        return;
    }

    for(int i = idx; i < N; i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        dfs(i, depth+1);
        mark[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);


    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
    }
    for(int i = 1; i <= N; i++) v.push_back(i);
    dfs(0, 0);

    cout << answer;
}