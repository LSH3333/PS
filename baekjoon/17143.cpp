#include <iostream>
using namespace std;

// 위, 아래, 오른쪽, 왼쪽
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

int R, C, M;

class Shark
{
public:
    int speed; // 속력
    int dir; // 방향
    int size; // 크기

    Shark():speed(0), dir(0), size(0) {}
    Shark(int s, int d, int z): speed(s), dir(d), size(z){}
};

Shark board[110][110];

void Move(int &r, int &c, int cnt, int &dir)
{
    while(cnt > 0)
    {
        // 위
        if(dir == 0)
        {
            // 방향꺾을 필요 없을때
            if(r - cnt > 0) { r -= cnt; cnt = 0; }
            else { cnt -= r-1; r = 1; dir = 1; }
        }
        // 아래
        else if(dir == 1)
        {
            if(r + cnt <= R) { r += cnt; cnt = 0; }
            else { cnt -= R-r; r = R; dir = 0; }
        }
        // 오른쪽
        else if(dir == 2)
        {
            if(c + cnt <= C) { c += cnt; cnt = 0; }
            else { cnt -= C-c; c = C; dir = 3; }
        }
        // 왼쪽
        else
        {
            if(c - cnt > 0) { c -= cnt; cnt = 0; }
            else { cnt -= c-1; c = 1; dir = 2; }
        }
    }
}

// 1초간 상어의 이동
void MoveSharks()
{
    Shark moved[110][110];

    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            Shark shark = board[i][j];
            if(shark.size == 0) continue;

            // shark 이동
            int r = i, c = j;
            Move(r, c, shark.speed, shark.dir);

            // [r][c]가 상어 최종 위치
            // 원래 있던 자리 비움
            Shark noShark;
            board[i][j] = noShark;
            // 새로운 위치에는 가장 큰 상어만
            if(shark.size > moved[r][c].size)
                moved[r][c] = shark;
        }
    }

    for(int i = 0; i <= R; i++)
    {
        for(int j = 0; j <= C; j++)
        {
            board[i][j] = moved[i][j];
        }
    }
}

void Print()
{
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            cout << board[i][j].size << ' ';
        } cout << endl;
    } cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C >> M;
    for(int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        // speed(s), dir(d), size(z)
        cin >> r >> c >> s >> d >> z;
        Shark shark{s, d-1, z};
        board[r][c] = shark;
    }
    

    int fisher = 0;
    int answer = 0;
    while(fisher++ < C)
    {
        // 상어 한 마리 잡을수 있다면 잡는다
        for(int r = 1; r <= R; r++)
        {
            if(board[r][fisher].size > 0)
            {
                answer += board[r][fisher].size;
                board[r][fisher] = {0, 0,0};
                break;
            }
        }

        // 상어 이동한다
        MoveSharks();
    }
    cout << answer;
}