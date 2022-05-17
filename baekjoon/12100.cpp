#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer;

bool IsItSame(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// 위로 움직임, 움직이기 전과 후과 같으면 return false
bool MoveUp(vector<vector<int>> &v)
{
    vector<vector<int>> copy = v;
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
    // 움직이기 전과 후과 동일함
    if(IsItSame(v, copy)) return false;
    return true;
}

bool MoveRight(vector<vector<int>> &v)
{
    vector<vector<int>> copy = v;
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
    if(IsItSame(v, copy)) return false;
    return true;
}

bool MoveDown(vector<vector<int>> &v)
{
    vector<vector<int>> copy = v;
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
    if(IsItSame(v, copy)) return false;
    return true;
}

bool MoveLeft(vector<vector<int>> &v)
{
    vector<vector<int>> copy = v;
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
    if(IsItSame(v, copy)) return false;
    return true;
}
//////////

bool Up(vector<vector<int>> &v)
{
    if(MoveUp(v)) return false;
    // 같은 숫자 합침
    for(int c = 0; c < N; c++)
    {
        int r;
        for(r = 0; r < N-1; r++)
        {
            if(v[r][c] == v[r+1][c]) { v[r][c] = v[r][c]*2; v[r+1][c] = 0; answer = max(answer, v[r][c]); }
        }
    }
    MoveUp(v);
    return true;
}

bool Right(vector<vector<int>> &v)
{
    if(MoveRight(v)) return false;
    for(int r = 0; r < N; r++)
    {
        for(int c = N-1; c >= 0; c--)
        {
            if(v[r][c] == v[r][c-1]) { v[r][c] = v[r][c]*2; v[r][c-1] = 0; answer = max(answer, v[r][c]);}
        }
    }
    MoveRight(v);
    return true;
}

bool Down(vector<vector<int>> &v)
{
    if(MoveDown(v)) return false;
    for(int c = 0; c < N; c++)
    {
        int r;
        for(r = N-1; r > 0; r--)
        {
            if(v[r][c] == v[r-1][c]) { v[r][c] = v[r][c]*2; v[r-1][c] = 0; answer = max(answer, v[r][c]);}
        }
    }
    MoveDown(v);
    return true;
}

bool Left(vector<vector<int>> &v)
{
    if(MoveLeft(v)) return false;
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N-1; c++)
        {
            if(v[r][c] == v[r][c+1]) { v[r][c] = v[r][c]*2; v[r][c+1] = 0; answer = max(answer, v[r][c]);}
        }
    }
    MoveLeft(v);
    return true;
}



// dir: 0 up, 1 right, 2 down, 3 left
bool Move(vector<vector<int>> &v, int dir)
{
    switch(dir)
    {
        case 0:
            if(Up(v)) return false;
        case 1:
            if(Right(v)) return false; break;
        case 2:
            if(Down(v)) return false; break;
        case 3:
            if(Left(v)) return false; break;
    }
    return true;
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

void dfs(vector<vector<int>> &v)
{
    for(int dir = 0; dir < 4; dir++)
    {
        
    }

    for(int dir = 0; dir < 4; dir++)
    {
        vector<vector<int>> copy = v;
        // 특정 방향으로 움직였을때 이동 있을때만
        if(!Move(v, dir)) dfs(v);
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

}