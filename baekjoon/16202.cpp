#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
int parentNode[1010];
bool mark[500000];

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}

// 루트에 있는 부모 노드를 재귀적으로 찾는다
int FindParentNode(int node)
{
    if(node == parentNode[node]) return node;
    return parentNode[node] = FindParentNode(parentNode[node]);
}

// 두 노드가 같은 부모를 갖는지 판단
bool IsParentSame(int node1, int node2)
{
    if(FindParentNode(node1) == FindParentNode(node2)) return true;
    return false;
}

// 두 노드를 같은 부모를 갖도록함
void Union(int node1, int node2)
{
    node1 = FindParentNode(node1);
    node2 = FindParentNode(node2);
    parentNode[node2] = node1;
}

int Kruskal(vector<vector<int>> &edges)
{
    // kruskal
    for(int i = 1; i <= N; i++) parentNode[i] = i;
    int minEdge = 100000000; // MST에 사용된 최소 비용 간선
    int answer = 0;
    int unionCnt = 0;
    for(auto x : edges)
    {
        // 부모 노드가 다르다면 사이클 x
        // 아직 사용하지 않은 간선만 사용 가능
        if(!IsParentSame(x[0], x[1]) && !mark[x[2]])
        {
            minEdge = min(minEdge, x[2]);
            answer += x[2];
            Union(x[0], x[1]);
            unionCnt++;
        }
    }
    // MST 발견
    if(unionCnt + 1 == N)
    {
        mark[minEdge] = true; // 최소 간선 사용 처리
        cout << answer << ' ';
    }
    else cout << 0 << ' ';

    return answer;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    vector<vector<int>> edges(M);
    for(int i = 1; i <= M; i++)
    {
        int a, b; cin >> a >> b;
        edges[i-1] = {a, b, i};
    }
    sort(edges.begin(), edges.end(), cmp);


    bool fail = false;
    while(K--)
    {
        if(fail) cout << 0 << ' ';
        if(Kruskal(edges) == 0) fail = true;
    }

}