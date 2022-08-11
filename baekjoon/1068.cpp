#include <iostream>
#include <vector>
using namespace std;

int cutNode;
int answer;
vector<int> edges[55];

void dfs(int node)
{
    if(edges[node].empty())
    {
        answer++;
        return;
    }

    int cnt = 0;
    for(auto next : edges[node])
    {
        if(next == cutNode) continue;
        cnt++;
        dfs(next);
    }
    if(cnt == 0) answer++;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    int rootNode;
    for(int i = 0; i < N; i++)
    {
        int parent; cin >> parent;
        if(parent == -1) { rootNode = i; continue; }
        edges[parent].push_back(i);
    }
    cin >> cutNode;

    if(cutNode == rootNode) { cout << 0; return 0;}
    dfs(rootNode);

    cout << answer;

}