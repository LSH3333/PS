#include <iostream>
#include <vector>
using namespace std;

vector<int> edges[100010];
int d[100010];

int dfs(int node)
{
    if(d[node] > 0) return 0;
    d[node] = 1;

    int cnt = 0;
    for(auto next : edges[node])
    {
        cnt += dfs(next);
    }
    d[node] += cnt;
    return d[node];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, R, Q; cin >> N >> R >> Q;

    for(int i = 0; i < N-1; i++)
    {
        int U, V; cin >> U >> V;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }
    vector<int> query(Q);
    for(int i = 0; i < Q; i++)
    {
        cin >> query[i];
    }

    dfs(R);

    for(auto x : query)
    {
        cout << d[x] << '\n';
    }
}