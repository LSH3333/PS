#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define UD 0
#define LR 1

int N;
char board[55][55];


struct Log
{
    pair<int,int> pos[3];
    int dir; // 0:상하 방향, 1: 좌우 방향
};

// mid 기준, 각도 기준
// 각도, 행, 열
bool mark[2][55][55];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// 이동 성공 여부, 이동 결과
pair<bool, Log> Move(Log log, int dir)
{
    for(int i = 0; i < 3; i++)
    {
        int r = log.pos[i].first;
        int c = log.pos[i].second;
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) return {false, log};
        if(board[nr][nc] == '1') return {false, log};
        log.pos[i].first = nr;
        log.pos[i].second = nc;
    }
    return {true, log};
}

pair<bool,Log> Rotate(Log log)
{
    int midR = log.pos[1].first;
    int midC = log.pos[1].second;

    for(int r = midR-1; r <= midR+1; r++)
    {
        for(int c = midC-1; c <= midC+1; c++)
        {
            if(r < 0 || r >= N || c < 0 || c >= N) return {false, log};
            if(board[r][c] == '1') return {false, log};
        }
    }

    // 회전 가능
    if(log.dir == UD)
    {
        log.pos[0] = {log.pos[1].first, log.pos[1].second+1};
        log.pos[2] = {log.pos[1].first, log.pos[1].second-1};
        log.dir = LR;
    }
    else
    {
        log.pos[0] = {log.pos[1].first-1, log.pos[1].second};
        log.pos[2] = {log.pos[1].first+1, log.pos[1].second};
        log.dir = UD;
    }
    return {true, log};
}

// 통나무 세 부분이 모두 목적지에 도착했다면 true return
bool CheckPos(const Log &log)
{
    for(int i = 0; i < 3; i++)
    {
        int r = log.pos[i].first;
        int c = log.pos[i].second;
        if(board[r][c] != 'E') return false;
    }
    return true;
}

int bfs(const Log &init)
{
    // log, depth
    queue<pair<Log, int>> q;
    q.push({init, 0});
    mark[init.dir][init.pos[1].first][init.pos[1].second] = true;

    while(!q.empty())
    {
        Log curLog = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(CheckPos(curLog)) return depth;

        // 상 하 좌 우
        for(int i = 0; i < 4; i++)
        {
            pair<bool, Log> res = Move(curLog, i);
            if(!res.first) continue; // 이동 실패
            // 이미 방문
            if(mark[res.second.dir][res.second.pos[1].first][res.second.pos[1].second]) continue;
            mark[res.second.dir][res.second.pos[1].first][res.second.pos[1].second] = true;
            q.push({res.second, depth+1});
        }

        // 회전
        pair<bool,Log> res = Rotate(curLog);
        if(res.first && !mark[res.second.dir][res.second.pos[1].first][res.second.pos[1].second])
        {
            mark[res.second.dir][res.second.pos[1].first][res.second.pos[1].second] = true;
            q.push({res.second, depth+1});
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    int lcnt = 0;
    Log log;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'B')
            {
                log.pos[lcnt].first = i;
                log.pos[lcnt++].second = j;
            }
        }
    }
    if(log.pos[0].first == log.pos[1].first) log.dir = 1; // 좌우 방향
    else log.dir = 0; // 상하 방향

    cout << bfs(log);
}