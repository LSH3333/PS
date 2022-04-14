#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[9][9];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 100;

// copy original map to result
void CopyMap(vector<vector<int>> &result)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            result[i][j] = board[i][j];
        }
    }
}

// 새롭게 만들어지는 맵 배열 &result를 받고, result[_r][_c]에서부터 dir 방향으로 시야닿는 범위를 7로 기록 
void CCTV1(vector<vector<int>> &result, int dir, int _r, int _c)
{
    int r = _r; int c = _c;
    while(true)
    {
        r = r + dr[dir];
        c = c + dc[dir];
        if(r < 0 || r >= N || c < 0 || c >= M) break;
        if(result[r][c] == 6) break;
        if(result[r][c] != 0) continue;
        result[r][c] = 7;
    }
}

void CCTV2(vector<vector<int>> &result, int dir, int _r, int _c)
{
    int r = _r; int c = _c;
    CCTV1(result, dir, r, c);
    dir = (dir + 2) % 4;
    CCTV1(result, dir, r, c);
}

void CCTV3(vector<vector<int>> &result, int dir, int _r, int _c)
{
    int r = _r; int c = _c;
    CCTV1(result, dir, r, c);
    dir = (dir + 1) % 4;
    CCTV1(result, dir, r, c);
}

void CCTV4(vector<vector<int>> &result, int dir, int _r, int _c)
{
    int r = _r; int c = _c;
    CCTV1(result, dir, r, c);
    dir = (dir + 1) % 4;
    CCTV1(result, dir, r, c);
    dir = (dir + 2) % 4;
    CCTV1(result, dir, r, c);
}

void CCTV5(vector<vector<int>> &result, int dir, int _r, int _c)
{
    int r = _r; int c = _c;
    CCTV4(result, dir, r, c);
    dir = (dir + 2) % 4;
    CCTV1(result, dir, r, c);
}

int Check(vector<pair<pair<int,int>,int>> &v)
{
    vector<vector<int>> result(N, vector<int>(M));
    CopyMap(result);

    for(int i = 0; i < v.size(); i++)
    {
        int r = v[i].first.first;
        int c = v[i].first.second;
        int cctv = board[v[i].first.first][v[i].first.second];
        int dir = v[i].second;

        if(cctv == 1) CCTV1(result, dir, r, c);
        else if(cctv == 2) CCTV2(result, dir, r, c);
        else if(cctv == 3) CCTV3(result, dir, r, c);
        else if(cctv == 4) CCTV4(result, dir, r, c);
        else CCTV5(result, dir, r, c);
    }

    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(result[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void dfs(vector<pair<pair<int,int>,int>> &v, int depth)
{
    if(depth == v.size())
    {
        answer = min(answer, Check(v));
        return;
    }

    for(int i = 0; i < 4; i++)
    {
        v[depth].second = i;
        dfs(v, depth+1);
    }
}

int main()
{
    cin >> N >> M;
    // {r, c}, 상태
    vector<pair<pair<int,int>,int>> v;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if(board[i][j] >= 1 && board[i][j] <= 5)
                v.push_back({{i,j}, -1});
        }
    }

    dfs(v, 0);

    cout << answer;
}