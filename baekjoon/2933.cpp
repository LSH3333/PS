#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;

struct Cluster
{
    vector<pair<int,int>> pos;
};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Print(const vector<vector<char>> &board)
{
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            cout << board[r][c];
        }cout<<endl;
    }cout<<endl;
}


// 클러스터들 나눔
void DivideClusters(int idx, vector<vector<char>> &board, vector<vector<int>> &mark, int _r, int _c)
{
    queue<pair<int,int>> q;
    q.push({_r,_c});
    mark[_r][_c] = idx;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] == '.' || mark[nr][nc] > 0) continue;
            mark[nr][nc] = idx;
            q.push({nr, nc});
        }
    }
}

// 클러스터 한칸 내림
void FallOneCluster(Cluster &cluster, vector<vector<int>> &mark, int idx)
{
    for(auto &pos : cluster.pos)
    {
        int r = pos.first, c = pos.second;
        mark[r][c] = 0;
    }

    for(auto &pos : cluster.pos)
    {
        int r = pos.first, c = pos.second;
        mark[r+1][c] = idx;
    }
}

// 내려가야할 클러스터 찾음, canFall = true면 내려가야할 클러스터
Cluster FindFallCluster(const vector<vector<int>> &mark, vector<vector<bool>> &visited, int _r, int _c, bool &canFall)
{
    Cluster cluster;
    canFall = true;
    queue<pair<int,int>> q;
    q.push({_r,_c});
    visited[_r][_c] = true;
    cluster.pos.push_back({_r, _c});

    while(!q.empty())
    {
        int r = q.front().first, c = q.front().second;

        q.pop();
        if(r+1 == R || (mark[r+1][c] != 0 && mark[r+1][c] != mark[_r][_c])) canFall = false;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(mark[nr][nc] != mark[_r][_c] || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr,nc});
            cluster.pos.push_back({nr,nc});
        }
    }

    return cluster;
}

// 중력 영향 받아야하는 클러스터 있는지 확인
// 있으면 내리고 true return
// 없으면 false return
void CheckClusters(vector<vector<char>> &board)
{
    vector<vector<int>> mark(R, vector<int>(C, 0));

    // 클러스터들 나누고
    int idx = 1;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(board[r][c] == '.' || mark[r][c] > 0) continue;
            DivideClusters(idx++, board, mark, r, c);
        }
    }

    // 떨어져야할 클러스터 찾고, 내림
    while(true)
    {
        vector<Cluster> fallClusters;
        vector<vector<bool>> visited(R, (vector<bool>(C, false)));
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                if(visited[r][c] || mark[r][c] == 0) continue;
                bool canFall = true;
                Cluster cluster = FindFallCluster(mark, visited, r, c, canFall);
                if(canFall) fallClusters.push_back(cluster);
            }
        }

        if(fallClusters.empty()) break;

        for(auto x : fallClusters)
            FallOneCluster(x, mark, mark[x.pos.front().first][x.pos.front().second]);
    }


    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(mark[r][c] == 0) board[r][c] = '.';
            else board[r][c] = 'x';
        }
    }
}

// dir:0 화살 왼쪽에서 오른쪽으로
void ShootArrow(int _r, int dir, vector<vector<char>> &board)
{
    // left -> right
    if(dir == 0)
    {
        for(int c = 0; c < C; c++)
        {
            if(board[_r][c] == 'x') { board[_r][c] = '.'; return; }
        }
    }
    else
    {
        for(int c = C-1; c >= 0; c--)
        {
            if(board[_r][c] == 'x') { board[_r][c] = '.'; return; }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            cin >> board[r][c];
        }
    }
    int N; cin >> N;
    int dir = 0;
    for(int i = 0; i < N; i++)
    {
        int loc; cin >> loc;
        int _r = R - loc;

        ShootArrow(_r, dir, board);
        CheckClusters(board);
        dir = (dir + 1) % 2;
    }

    Print(board);

}
