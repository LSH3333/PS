#include <iostream>
#include <vector>
using namespace std;

int N, M, W;

bool Bellman_Ford(vector<pair<pair<int,int>,int>> &edges)
{
    vector<int> d(N+1, -1);
    d[1] = 0;
    for(int i = 0; i < N-1; i++)
    {
        for(auto x : edges)
        {
            int start = x.first.first;
            int end = x.first.second;
            int cost = x.second;

            int nextDist = d[start] + cost;
            if(nextDist < d[end]) d[end] = nextDist;
        }
    }

    for(auto x : edges)
    {
        int start = x.first.first;
        int end = x.first.second;
        int cost = x.second;

        int nextDist = d[start] + cost;
        if(nextDist < d[end]) return true;
    }
    return false;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        cin >> N >> M >> W;
        vector<pair<pair<int,int>,int>> edges;
        for(int i = 0; i < M; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            edges.push_back({{a,b},c});
            edges.push_back({{b,a},c});
        }
        for(int i = 0; i < W; i++)
        {
            int a, b, c; cin >> a >> b >> c;
            edges.push_back({{a,b},-c});
        }

        if(Bellman_Ford(edges)) cout << "YES\n";
        else cout << "NO\n";
    }

}