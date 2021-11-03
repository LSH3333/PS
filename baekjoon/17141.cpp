#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m;
int ans = 999999999;
int map[51][51];
bool visited[51][51];
bool mark[11];
vector<pair<int,int>> virusPutLoc;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// m개 지점에 바이러스를 살포했을때, 벽을 제외한 모든곳이 감염되었는지 판별
bool IsAllInfected()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 1) continue; // 벽은 제외
            if(!visited[i][j]) return false;
        }
    }
    return true;
}


void InitVisited()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
}

void bfs()
{
    // {r,c}, {time}
    queue<pair<pair<int,int>,int>> q;
    // 현재 바이러스를 살포하기로한 m개의 좌표를 큐에 푸쉬한다
    for(int i = 0; i < virusPutLoc.size(); i++)
    {
        if(mark[i])
        {
            q.push({{virusPutLoc[i]},0});
            visited[virusPutLoc[i].first][virusPutLoc[i].second] = true;
        }
    }

    int time = 0;
    while(!q.empty())
    {
        int _r = q.front().first.first;
        int _c = q.front().first.second;
        time = q.front().second;
        //if(time > maxTime) maxTime = time;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = _r + dr[i];
            int nc = _c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

            if(!visited[nr][nc] && map[nr][nc] != 1)
            {
                visited[nr][nc] = true;
                q.push({{nr,nc}, time+1});
            }
        }
    }

    // 벽을 제외한 모든곳이 감염되었다면 최소시간 갱신
    if(IsAllInfected())
        ans = min(ans, time);

    InitVisited(); // visited 배열 초기화
}

// virusPutLoc.size()개 중에서 m개의 바이러스 살포 위치를 정한다 (조합)
void dfs(int index, int numOfVirus)
{
    // m개의 위치를 정했다
    if(numOfVirus == m)
    {
        // 바이러스 살포
        bfs();

        return;
    }

    for(int i = index; i < virusPutLoc.size(); i++)
    {
        if(mark[i]) continue;
        mark[i] = true;
        dfs(i, numOfVirus+1);
        mark[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            // virus를 놓을수 있는 칸의 좌표를 벡터에 저장해놓는다
            if(map[i][j] == 2)
                virusPutLoc.push_back({i,j});
        }
    }

    dfs(0,0);

    // ans가 초기값에서 변하지 않았다면 바이러스를 어떻게 놓아도 모든 빈칸에 바이러스를 퍼트릴수 없다는 것
    if(ans == 999999999)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

}