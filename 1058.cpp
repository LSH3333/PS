#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int ans = 0;
// 인접리스트 형태로
vector<int> edge[51];
bool mark[51];

int bfs(int idx)
{
    // 다른 bfs 탐색을 위해 초기화
    fill_n(mark, n, false);
    int cnt = 0;
    queue<pair<int,int>> q;

    q.push({idx,0});
    mark[idx] = true;

    while(!q.empty())
    {
        int v = q.front().first;
        int depth = q.front().second;
        q.pop();

        // 탐색하는 기준 정점으로 부터 2이상 떨어져있으면 2친구가 아니다
        if(depth == 2) break;

        for(int x : edge[v])
        {
            // 이미 방문했다면 continue
            if(mark[x]) continue;

            mark[x] = true;
            // 방문하는 정점,깊이를 큐에 푸쉬
            q.push({x, depth+1});
            // 친구수 카운트 증가
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    // inputs
    cin >> n;
    //
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            if(c == 'Y')
            {
                edge[i].push_back(j);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, bfs(i));
    }

    cout << ans;
}