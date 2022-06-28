#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int dr[] = {-1,0,1,0};
int dc[] = {0, 1, 0, -1};

// 지운 블록 있다면 return true
bool bfs(int _r, int _c, vector<vector<int>> &board, vector<vector<bool>> &mark)
{
    // 탐색 지점들 저장
    vector<pair<int,int>> pos;
    queue<pair<pair<int,int>,int>> q;
    mark[_r][_c] = true;
    pos.push_back({_r,_c});
    q.push({{_r,_c}, 1});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= 10) continue;
            if(board[nr][nc] != board[_r][_c] || mark[nr][nc]) continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, depth+1});
            pos.push_back({nr,nc});
        }
    }

    // 방문 지점 몇개인지 확인
    // K개 이상 인접해 있다면 지움
    if(pos.size() >= K)
    {
        for(auto x : pos)
        {
            board[x.first][x.second] = 0;
        }
        return true;
    }
    return false;
}

void Gravity(vector<vector<int>> &board)
{
    for(int c = 0; c < 10; c++)
    {
        vector<int> v;
        int r;
        for(r = N-1; r >= 0; r--)
        {
            if(board[r][c] != 0) v.push_back(board[r][c]);
            board[r][c] = 0;
        }
        r = N-1;
        for(int j = 0; j < v.size(); j++)
        {
            board[r--][c] = v[j];
        }
    }
}

// 지운 블록들 있으면 return true
bool OneTurn(vector<vector<int>> &board)
{
    bool removed = false;
    vector<vector<bool>> mark(N, vector<bool>(10, false));
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < 10; c++)
        {
            if(mark[r][c] || board[r][c] == 0) continue;
            if(bfs(r, c, board, mark)) removed = true;
        }
    }
    Gravity(board);
    if(removed) return true;
    else return false;
}

void Print(const vector<vector<int>> &board)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << board[i][j];
        }cout<<endl;
    }cout<<endl;
}

int main()
{
    cin >> N >> K;
    vector<vector<int>> board(N, vector<int>(10));
    for(int i = 0; i < N; i++)
    {
        string str; cin >> str;
        for(int j = 0; j < 10; j++)
        {
            board[i][j] = str[j]-'0';
        }
    }

    while(OneTurn(board));

    Print(board);
}