#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
int totalPipes;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0 ,-1};

#define UP {5,7,1,4}
#define RIGHT {6,7,3,4}
#define DOWN {5,7,2,3}
#define LEFT {6,7,1,2}



vector<vector<int>> roads[8] =
        {
                {},
                {{}, RIGHT, DOWN, {}},
                {UP, RIGHT, {}, {}},
                {UP, {}, {}, LEFT},
                {{}, {}, DOWN, LEFT},
                {UP, {}, DOWN, {}},
                {{}, RIGHT, {}, LEFT},
                {UP, RIGHT, DOWN, LEFT}
        };


int missingR, missingC, missingDir;

// 현재 블록 cur과 방향 dir를 토대로 다음 블록 next로 이동 가능한지 판단
bool Check(int cur, int dir, int next)
{
    if(roads[cur][dir].empty()) return false;
    for(int i = 0; i < roads[cur][dir].size(); i++)
    {
        if(roads[cur][dir][i] == next) return true;
    }
    return false;
}

int CountPipe(const  vector<vector<int>> &mark, const vector<vector<int>> &board)
{
    int cnt = 0;
    for(int r = 1; r <= R; r++)
    {
        for(int c = 1; c <= C; c++)
        {
            if(board[r][c] == 0 || board[r][c] == -2 || board[r][c] == -1) continue;
            if(mark[r][c]) cnt++;
        }
    }
    return cnt;
}

bool bfs(int MR, int MC, const vector<vector<int>> &board)
{
    vector<vector<int>> mark(R+1, vector<int>(C+1, 0));
    // {r,c},dir
    queue<pair<pair<int,int>,int>> q;
    mark[MR][MC]++;
    q.push({{MR, MC}, -1});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second;
        q.pop();

        missingR = r; missingC = c; missingDir = dir;

        if(CountPipe(mark,board) == totalPipes)
        {
            for(int i = 0; i < roads[board[r][c]].size(); i++)
            {
                if(roads[board[r][c]][i].empty()) continue;
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(board[nr][nc] == -2) return true;
            }
        }

        // 이동
        for(int i = 0; i < 4; i++)
        {
            if(board[r][c] == 7 && i != dir) continue; // 현재 십자블록이라면 같은 방향으로만 이동 가능
            if(dir != -1 && i == (dir+2)%4) continue; // 왔던 방향으로는 가지 않음
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if(board[nr][nc] == 0) continue;
            // 다음 블록이 십자 블록이고 2번 방문했다면 이동 불가
            if(board[nr][nc] == 7 && mark[nr][nc] >= 2) continue;
            // 십자 블록 이외에는 단 한번만 방문 가능
            if(board[nr][nc] != 7 && mark[nr][nc] > 0) continue;
            // 다음 블록과 안맞음
            if((board[r][c] > 0) && !Check(board[r][c], i, board[nr][nc])) continue;

            mark[nr][nc]++;
            q.push({{nr,nc}, i});
            break;
        }
    }

    for(int i = 0; i < roads[board[missingR][missingC]].size(); i++)
    {
        if(roads[board[missingR][missingC]][i].empty()) continue;
        int nr = missingR + dr[i];
        int nc = missingC + dc[i];
        if(nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if(board[nr][nc] != 0) continue;
        missingR = nr; missingC = nc;
    }
    return false;
}



int main()
{
    cin >> R >> C;
    vector<vector<int>> board(R+1, vector<int>(C+1));
    int MR, MC, ZR, ZC;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            char c; cin >> c;
            if(c != '.') totalPipes++;
            if(c == '.') board[i][j] = 0;
            else if(c == '|') { board[i][j] = 5; }
            else if(c == '-') { board[i][j] = 6; }
            else if(c == '+') { board[i][j] = 7; }
            else if(c == 'M') { board[i][j] = -1; MR = i; MC = j; }
            else if(c == 'Z') { board[i][j] = -2; ZR = i; ZC = j; }
            else { board[i][j] = c-'0'; }
        }
    }
    totalPipes = totalPipes -2 + 1; // M,Z 제외, 사라진 파이프 추가


    // 사라진 지점 찾음
    bfs(MR, MC, board);
    int mR = missingR, mC = missingC;

    for(int i = 1; i <= 7; i++)
    {
        board[mR][mC] = i;

        if(bfs(MR, MC, board))
        {
            char tmp;
            if(i == 5) tmp = '|';
            else if(i == 6) tmp = '-';
            else if(i == 7) tmp = '+';
            else tmp = (char)(i+'0');
            cout << mR << ' ' << mC << ' ' << tmp;
            return 0;
        }
        board[mR][mC] = 0;
    }



}