#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int answer = 0;
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
    }

    vector<int> v;
    for(int i = 1; i <= N; i++) v.push_back(i);
    vector<bool> mark(N, false);
    for(int i = 0; i < 3; i++) mark[i] = true;

    do {
        vector<int> comb;
        for(int i = 0; i < v.size(); i++)
            if(mark[i]) comb.push_back(v[i]);
            
        if(IsPossible(comb)) answer++;

    } while(prev_permutation(mark.begin(), mark.end()));
    cout << answer;
}