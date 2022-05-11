#include <iostream>
using namespace std;

int N, M, H;
int board[40][40];
int answer = 10;

// idx번 세로선 사다리를 타서 도착하는 곳 리턴
int ClimbLadder(int idx)
{
    int c = idx;
    int r = 1;
    while(r <= H)
    {
        if(board[r][c] == 1 || board[r][c] == 2) c++;
        else if(c-1 >= 0 && (board[r][c-1] == 1 || board[r][c-1] == 2)) c--;

        r++;
    }
    return c;
}

void Print()
{
    for(int i = 0; i <= H; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            cout << board[i][j] << ' ';
        }cout << endl;
    }cout << endl;
}

void MakeLadders(int _r, int depth, int cnt)
{
    if(depth == cnt)
    {
        bool isTrue = true;
        for(int i = 1; i <= N; i++)
        {
            if(ClimbLadder(i) != i)
            {
                isTrue = false;
                break;
            }
        }
        // 조건 통과
        if(isTrue) answer = min(answer, cnt);

        return;
    }

    // 조합이므로 _r행부터 탐색 시작 
    for(int i = _r; i <= H; i++)
    {
        for(int j = 1; j < N; j++)
        {
            // 최초 사다리, 새롭게 놓은 사다리 있는 지점
            if(board[i][j] == 1 || board[i][j] == 2) continue;
            if(board[i][j-1] == 1 || board[i][j-1] == 2) continue;
            board[i][j] = 2;
            MakeLadders(i, depth+1, cnt);
            board[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    // 세로선의 개수 N, 가로선의 개수 M, 세로선마다 가로선을 놓을수 있는 위치 수 H
    cin >> N >> M >> H;
    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        board[a][b] = 1;
    }

    for(int cnt = 0; cnt <= 3; cnt++)
    {
        MakeLadders(1, 0, cnt);
    }


    if(answer > 3) answer = -1;
    cout << answer;
}