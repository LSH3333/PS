#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 가수의 수, 보조 PD의 수
int N, M, total;
int entry[1010];
vector<int> edges[1010];
bool mark[1010];
vector<int> answer;

bool TopologySort()
{
    queue<int> q;
    for(int i = 1; i <= N; i++)
    {
        if(entry[i] == 0) { q.push(i); mark[i] = true; }
    }

    for(int i = 0; i < N; i++)
    {
        int node = q.front(); q.pop();
        answer.push_back(node);

        for(auto next : edges[node])
        {
            if(mark[next]) continue; // 이미 사용한 노드

            if(--entry[next] == 0)
            {
                q.push(next); mark[next] = true;
            }
        }

        if(i != N-1 && q.empty()) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int n; cin >> n;
        total += n;
        vector<int> v(n);
        for(int j = 0; j < n; j++) cin >> v[j];
        for(int j = 0; j < n-1; j++)
        {
            edges[v[j]].push_back(v[j+1]);
            entry[v[j+1]]++;
        }
    }

    bool res = TopologySort();
    if(res) for(auto x : answer) cout << x << '\n';
    else cout << 0;

}