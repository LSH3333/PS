#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
char input[51][51];
bool mark[51];
vector<int> v[51];

int ans = 0;

// bool mark[] 배열 false로 초기화
void InitMark()
{
    for(int i = 0; i < n; i++)
    {
        mark[i] = false;
    }
}

int bfs(int idx)
{
    InitMark();

    // (idx, depth)
    queue<pair<int,int>> q;

    q.push({idx,0});
    mark[idx] = true;

    while(!q.empty())
    {
        int ver = q.front().first;
        int depth = q.front().second;
        q.pop();

        // 탐색하는 기준 정점으로 부터 2이상 떨어져있으면 2친구가 아니므로 break
        if(depth == 2) break;

        for(auto x : v[ver])
        {
            // 이미 방문했다면 continue
            if(mark[x]) continue;

            mark[x] = true;
            // 방문하는 정점과 깊이를 큐에 푸쉬
            q.push({x, depth+1});
        }
    }

    // 방문한 정점들의 수
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        res += mark[i];
    }

    // 자기 자신은 빼고 카운트
    return res-1;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        scanf("%s", input[i]);
    }
    /*
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << input[i][j];
        } cout << endl;
    }
     */

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(input[i][j] == 'Y')
                v[i].push_back(j);
        }
    }
    /*
    for(int i = 0; i < n; i++)
    {
        for(auto x : v[i]) cout << x << ' ';
        cout << endl;
    }
     */

    for(int i = 0; i < n; i++)
    {
        ans = max(ans, bfs(i));
    }

    cout << ans;
}