#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;
char board[51][51];
int water[51][51];
int hedge[51][51];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct loc
{
    int type; // 0:홍수, 1:고슴도치
    int r;
    int c;
    int depth;
};

// 고슴도치, 홍수 같은 큐에 넣어야함
int bfs(const vector<pair<int,int>> &waterLoc, const int sR, const int sC)
{
    queue<loc> q;
    // 홍수 최초 위치
    for(auto x : waterLoc)
    {
        water[x.first][x.second] = 1;
        q.push({0, x.first, x.second, 1});
    }
    // 고슴도치 최초 위치
    hedge[sR][sC] = 1;
    q.push({1, sR, sC, 1});

    while(!q.empty())
    {
        int type = q.front().type;
        int r = q.front().r;
        int c = q.front().c;
        int depth = q.front().depth;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            // 홍수
            if(type == 0)
            {
                // 이미 홍수 or 비버굴 'D' or 바위 'X' 는 이동 불가
                if(water[nr][nc] > 0 || board[nr][nc] == 'D' || board[nr][nc] == 'X') continue;
                water[nr][nc] = depth+1;
                q.push({0, nr, nc, depth+1});
            }
            else // 고슴도치
            {
                // 비버굴 도착
                if(board[nr][nc] == 'D') return depth;
                // 바위 'X' or 이미 홍수 or 이미방문 은 이동 불가
                if(board[nr][nc] == 'X' || water[nr][nc] > 0 || hedge[nr][nc] > 0) continue;
                hedge[nr][nc] = depth+1;
                q.push({1, nr, nc, depth+1});
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int,int>> waterLoc; // 홍수 시작 위치
    int sR, sC; // S 위치
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == '*') waterLoc.push_back({i,j});
            else if(board[i][j] == 'S') { sR = i; sC = j; }
        }
    }

    int res = bfs(waterLoc, sR, sC);
    if(res == -1) cout << "KAKTUS";
    else cout << res;
}