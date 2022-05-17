#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer;

// 위로 움직임, 움직이기 전과 후과 같으면 return false
void MoveUp(vector<vector<int>> &v)
{
    for(int c = 0; c < N; c++)
    {
        vector<int> num;
        int r;
        for(r = 0; r < N; r++)
        {
            if(v[r][c] != 0) { num.push_back(v[r][c]); v[r][c] = 0; }
        }

        r = 0;
        for(auto x : num) v[r++][c] = x;
    }

}

void MoveRight(vector<vector<int>> &v)
{
    for(int r = 0; r < N; r++)
    {
        vector<int> num;
        int c;
        for(c = N-1; c >= 0; c--)
        {
            if(v[r][c] != 0) { num.push_back(v[r][c]); v[r][c] = 0; }
        }
        c = N-1;
        for(auto x : num) v[r][c--] = x;
    }
}

void MoveDown(vector<vector<int>> &v)
{
    for(int c = 0; c < N; c++)
    {
        vector<int> num;
        int r;
        for(r = N-1; r >= 0; r--)
        {
            if(v[r][c] != 0) { num.push_back(v[r][c]); v[r][c] = 0; }
        }

        r = N-1;
        for(auto x : num) v[r--][c] = x;
    }
}

void MoveLeft(vector<vector<int>> &v)
{
    for(int r = 0; r < N; r++)
    {
        vector<int> num;
        int c;
        for(c = 0; c < N; c++)
        {
            if(v[r][c] != 0) { num.push_back(v[r][c]); v[r][c] = 0; }
        }
        c = 0;
        for(auto x : num) v[r][c++] = x;
    }
}
//////////


void Up(vector<vector<int>> &v)
{
    MoveUp(v);
    // 같은 숫자 합침
    for(int c = 0; c < N; c++)
    {
        int r;
        for(r = 0; r < N-1; r++)
        {
            if(v[r][c] == v[r+1][c]) { v[r][c] = v[r][c]*2; v[r+1][c] = 0;  }
        }
    }
    MoveUp(v);
}

void Right(vector<vector<int>> &v)
{
    MoveRight(v);

    for(int r = 0; r < N; r++)
    {
        for(int c = N-1; c >= 0; c--)
        {
            if(v[r][c] == v[r][c-1]) { v[r][c] = v[r][c]*2; v[r][c-1] = 0; }
        }
    }
    MoveRight(v);
}

void Down(vector<vector<int>> &v)
{
    MoveDown(v);
    for(int c = 0; c < N; c++)
    {
        int r;
        for(r = N-1; r > 0; r--)
        {
            if(v[r][c] == v[r-1][c]) { v[r][c] = v[r][c]*2; v[r-1][c] = 0; }
        }
    }
    MoveDown(v);
}

void Left(vector<vector<int>> &v)
{
    MoveLeft(v);
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N-1; c++)
        {
            if(v[r][c] == v[r][c+1]) { v[r][c] = v[r][c]*2; v[r][c+1] = 0; }
        }
    }
    MoveLeft(v);
}



// dir: 0 up, 1 right, 2 down, 3 left
void Move(vector<vector<int>> &v, int dir)
{
    switch(dir)
    {
        case 0:
            Up(v); break;
        case 1:
            Right(v); break;
        case 2:
            Down(v); break;
        case 3:
            Left(v); break;
        default:
            break;
    }
}

void Print(vector<vector<int>> &v)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << v[i][j] << ' ';
        }cout << endl;
    }cout << endl;
}

void dfs(vector<vector<int>> &v, int depth)
{
    if(depth == 5)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                answer = max(answer, v[i][j]);
            }
        }
        return;
    }

    for(int dir = 0; dir < 4; dir++)
    {
        vector<vector<int>> copy = v;
        Move(v, dir);
        dfs(v, depth+1);
        v = copy;
    }

}

int main()
{
    cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    dfs(v, 0);
    cout << answer;

}