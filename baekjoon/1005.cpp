#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, W;

void Input(vector<int> edges[], vector<int> &costs, vector<int> &v, vector<int> &startNodes)
{
    for(int i = 1; i <= N; i++) cin >> costs[i];
    for(int i = 0; i < K; i++)
    {
        int X, Y; cin >> X >> Y;
        edges[X].push_back(Y);
        v[Y]++;
    }
    cin >> W;

    for(int i = 1; i <= N; i++)
    {
        if(v[i] == 0) startNodes.push_back(i);
    }
}

int bfs(const vector<int> edges[], const vector<int> &costs, vector<int> &v, const vector<int> &startNodes)
{
    vector<int> d(N+1, 0);
    queue<int> q;
    for(auto x : startNodes) { q.push(x); d[x] = costs[x]; }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto next : edges[node])
        {
            // 다음 건물 건설 시간 = 현재 건물 건설 시간 + 다음 건물 건설 시간
            d[next] = max(d[next], d[node] + costs[next]);
            v[next]--;
            if(v[next] == 0) // 모든 경로 탐색 완료, 다음으로 넘어가도 됨
            {
                q.push(next);
            }
        }
    }

    return d[W];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        cin >> N >> K;
        vector<int> edges[N+1];
        vector<int> costs(N+1);
        vector<int> v(N+1); // v[i] : i번 노드로 들어가는 엣지 갯수
        vector<int> startNodes; // 시작 노드
        Input(edges, costs, v, startNodes);

        int res = bfs(edges, costs, v, startNodes);
        cout << res << '\n';
    }


}