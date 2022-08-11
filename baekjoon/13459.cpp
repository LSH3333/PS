#include <iostream>
using namespace std;

struct Ball
{
    int r;
    int c;
};

int N, M;
char board[11][11];
Ball goal;
int answer;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void Move(Ball &red, Ball &blue, int dir)
{
    Ball b_red = {red.r, red.c};
    Ball b_blue = {blue.r, blue.c};

    while(board[red.r][red.c] == '.')
    {
        red.r += dr[dir];
        red.c += dc[dir];
    }
    if(board[red.r][red.c] == '#') { red.r -= dr[dir]; red.c -= dc[dir]; }

    while(board[blue.r][blue.c] == '.')
    {
        blue.r += dr[dir];
        blue.c += dc[dir];
    }
    if(board[blue.r][blue.c] == '#') { blue.r -= dr[dir]; blue.c -= dc[dir]; }

    if(red.r == blue.r && red.c == blue.c)
    {
        if(red.r == goal.r && red.c == goal.c) return; // 골 지점

        if(dir == 0)
        {
            if(b_red.r > b_blue.r) red.r++;
            else blue.r++;
        }
        else if(dir == 1)
        {
            if(b_red.c < b_blue.c) red.c--;
            else blue.c--;
        }
        else if(dir == 2)
        {
            if(b_red.r < b_blue.r) red.r--;
            else blue.r--;
        }
        else
        {
            if(b_red.c > b_blue.c) red.c++;
            else blue.c++;
        }
    }
}

void dfs(Ball &red, Ball &blue, int depth)
{
    if(depth >= 10) return;
    if(answer == 1) return;

    for(int dir = 0; dir < 4; dir++)
    {
        Ball b_red = red;
        Ball b_blue = blue;
        Move(red, blue, dir);

        // 빨강공만 골에 도착
        if(red.r == goal.r && red.c == goal.c && (blue.r != goal.r || blue.c != goal.c))
        {
            answer = 1; return;
        }
        // 그 외 모든 경우
        dfs(red, blue, depth+1);
        red = b_red;
        blue = b_blue;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    Ball red{0,0};
    Ball blue{0,0};
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'R') { board[i][j] = '.'; red = {i, j}; }
            else if(board[i][j] == 'B') { board[i][j] = '.'; blue = {i, j}; }
            else if(board[i][j] == 'O') { goal = {i, j}; }
        }
    }

    dfs(red, blue, 0);
    cout << answer;

}