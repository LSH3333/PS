#include <iostream>
using namespace std;

bool board[100][100];
int answer;


// 전달 받은 기준 좌표 기준으로, 전달 받은 높이 너비의 직사각형 가능한지 확인
bool IsItValid(int _r, int _c, int h, int w)
{
    for(int r = _r; r < _r+h; r++)
    {
        for(int c = _c; c < _c+w; c++)
        {
            if(r >= 100 || c >= 100) return false;
            if(!board[r][c]) return false;
        }
    }
    return true;
}

// 높이, 너비
void CheckArea(int _r, int _c)
{
    for(int h = 1; h <= 100-_r; h++)
    {
        for(int w = 1; w <= 100-_c; w++)
        {
            if(IsItValid(_r, _c, h, w)) answer = max(answer, h*w);
        }
    }
}


int main()
{
    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        int C, R; cin >> C >> R;
        for(int r = R; r < R+10; r++)
        {
            for(int c = C; c < C+10; c++)
            {
                board[r][c] = true;
            }
        }
    }

    // 기준이 되는 좌표
    for(int r = 0; r < 100; r++)
    {
        for(int c = 0; c < 100; c++)
        {
            CheckArea(r, c);
        }
    }
    cout << answer;
}