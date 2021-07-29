#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
int ans = 999;
int map_org[51][51];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool mark[51][51];

// mark 초기화
void InitMark()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //map[i][j] = map_org[i][j]; 맵복사 필요없음
            mark[i][j] = false; // mark도 초기화
        }
    }
}


// 바이러스 살포안된곳 있는지 판별
bool AllVisited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 벽이면 continue
            if(map_org[i][j] == 1) continue;
            // 방문안한곳 있으면 false 리턴
            if(!mark[i][j]) return false;
        }
    }
    return true;
}

void bfs()
{
    queue<pair<pair<int,int>,int>> q;
    // 바이러스 살포하기로 정한 위치를 큐에 푸쉬한다
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map_org[i][j] == 5)
            {
                q.push({{i,j},0});
                mark[i][j] = true;
            }
        }
    }

    int time;
    while(!q.empty())
    {
        int _r = q.front().first.first;
        int _c = q.front().first.second;
        time = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = _r + dr[i];
            int nc = _c + dc[i];

            // 범위 벗어남
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            // 벽이거나 이미 방문했다면 continue
            if(map_org[nr][nc] == 1 || mark[nr][nc]) continue;

            mark[nr][nc] = true;
            q.push({{nr,nc}, time+1});
        }
    }


    // 바이러스가 모든곳에 살포되었다면 최소시간 갱신
    if(AllVisited())
    {
        ans = min(ans, time);
    }
}



// m개의 바이러스를 놓을곳을 찾는다
void dfs(int virusNum)
{
    // 놓을수 있는 모든 바이러스를 놓았다면
    if(virusNum == m)
    {
        InitMark();
        bfs();

        return;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 바이러스를 놓을수 있는곳이면
            if(map_org[i][j] == 2)
            {
                map_org[i][j] = 5; // virus 표시
                dfs(virusNum+1);
                map_org[i][j] = 2;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map_org[i][j];
        }
    }

    dfs(0);

    // ans가 최초값에서 변하지 않았다면 어떻게 놓아도 모든 빈칸에 바이러스를 살포할수 없다는 뜻이다
    if(ans == 999)
        ans = -1;

    cout << ans;

}

