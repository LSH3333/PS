#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int board[9][9];

void Print()
{
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c < 9; c++)
        {
            cout << board[r][c] << ' ';
        } cout << '\n';
    } cout << '\n';
}

int CalStartPos(int n)
{
    if(n == 0 || n == 1 || n == 2) return 0;
    if(n == 3 || n == 4 || n == 5) return 3;
    if(n == 6 || n == 7 || n == 8) return 6;
}

bool Check(int _r, int _c)
{
    // 행 체크
    bool mark[10];
    memset(mark, false, sizeof(mark));
    for(int i = 0; i < 9; i++)
    {
        if(board[_r][i] == 0) continue;
        if(mark[board[_r][i]]) return false;
        mark[board[_r][i]] = true;
    }

    // 열 체크
    memset(mark, false, sizeof(mark));
    for(int i = 0; i < 9; i++)
    {
        if(board[i][_c] == 0) continue;
        if(mark[board[i][_c]]) return false;
        mark[board[i][_c]] = true;
    }

    // 사각형 체크
    memset(mark, false, sizeof(mark));
    int sr = CalStartPos(_r), sc = CalStartPos(_c);
    for(int r = sr; r < sr + 3; r++)
    {
        for(int c = sc; c < sc + 3; c++)
        {
            if(board[r][c] == 0) continue;
            if(mark[board[r][c]]) return false;
            mark[board[r][c]] = true;
        }
    }
    return true;
}

void dfs(vector<pair<int,int>> &v, int idx)
{
    if(idx == v.size())
    {
        Print();
        exit(0);
    }

    int r = v[idx].first, c = v[idx].second;
    for(int i = 1; i <= 9; i++)
    {
        board[r][c] = i;
        if(Check(r,c))
        {
            dfs(v, idx+1);
        }
        board[r][c] = 0;
    }
}


int main()
{
    vector<pair<int,int>> v;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 0) v.push_back({i, j});
        }
    }

    dfs(v, 0);
}