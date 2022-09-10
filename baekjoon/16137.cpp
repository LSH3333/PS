#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define CLIFF 0
#define GROUND 1
#define INF 10000000
#define NO 0
#define YES 1

int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// 오작교를 놓을수 없는 절벽 -1 처리
void FindBridgeCandidate(vector<vector<int>> &board)
{
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            if(board[r][c] != 0) continue;
            // 절벽이 교차함
            if(r-1 >= 0 && board[r-1][c] != 1 && c+1 < N && board[r][c+1] != 1) board[r][c] = -1;
            else if(c+1 < N && board[r][c+1] != 1 && r+1 < N && board[r+1][c] != 1) board[r][c] = -1;
            else if(r+1 < N && board[r+1][c] != 1 && c-1 >= 0 && board[r][c-1] != 1) board[r][c] = -1;
            else if(c-1 >= 0 && board[r][c-1] != 1 && r-1 >= 0 && board[r-1][c] != 1) board[r][c] = -1;
        }
    }

}

struct Info
{
    int r;
    int c;
    bool constructed; // true시 다리 이미 지었음
};

void Print(const vector<vector<vector<int>>> &mark)
{
    for(int r  = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            string a = mark[r][c][0] == INF ? "INF" : to_string(mark[r][c][0]);
            string b = mark[r][c][1] == INF ? "INF" : to_string(mark[r][c][1]);
            printf("(%5d, %5d) ", mark[r][c][0], mark[r][c][1]);
        }cout<<endl;
    }cout<<endl;
}

int bfs(const vector<vector<int>> &board)
{
    queue<Info> q;
    vector<vector<vector<int>>> mark(N+1, vector<vector<int>>(N+1, vector<int>(2, INF)));
    q.push({0, 0, false});
    mark[0][0][YES] = 0;
    mark[0][0][NO] = 0;

    while (!q.empty())
    {
        Info info = q.front();
        q.pop();
        int r = info.r, c = info.c;
        bool constructed = info.constructed;


        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;


            // 다음 위치가 땅
            if(board[nr][nc] == GROUND)
            {
                if(mark[r][c][constructed]+1 < mark[nr][nc][constructed])
                {
                    mark[nr][nc][constructed] = mark[r][c][constructed]+1;
                    q.push({nr, nc, constructed});
                }
            }
                // 다음 위치가 오작교
            else if(board[nr][nc] >= 2)
            {
                if(board[r][c] == GROUND)
                {
                    int time = board[nr][nc];
                    while(mark[r][c][constructed]+1 > time) time += board[nr][nc];
                    mark[nr][nc][constructed] = time;
                    q.push({nr,nc,constructed});
                }
            }
                // 다음 위치가 절벽
            else if(board[nr][nc] == CLIFF)
            {
                // 현재 위치가 땅이고, 아직 오작교 건설 안했고, 주기 M 오작교 건설해서 건너갈수 있음
//                if(board[r][c] == GROUND && !constructed && (mark[r][c][constructed]+1) % M == 0)
//                {
//                    mark[nr][nc][YES] = mark[r][c][constructed]+1;
//                    q.push({nr, nc, YES});
//                }
//
                if(board[r][c] == GROUND && !constructed)
                {
                    int time = M;
                    while(mark[r][c][constructed]+1 > time) time += M;
                    mark[nr][nc][YES] = time;
                    q.push({nr,nc,YES});
                }
            }
        }
    }

    return min(mark[N - 1][N - 1][NO], mark[N - 1][N - 1][YES]);
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> board(N+1, vector<int>(N+1));
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            cin >> board[r][c];
        }
    }


    // 오작교를 놓을수 있는 절벽 후보들
    FindBridgeCandidate(board);


    cout << bfs(board);


}