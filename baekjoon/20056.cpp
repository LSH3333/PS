#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Fireball
{
    int m; // 질량
    int s; // 속력
    int d; // 방향
};

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K;
vector<Fireball> board[52][52];

void Print(vector<Fireball> newBoard[][52])
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(newBoard[i][j].empty()) cout << '0' << ' ';
            else cout << newBoard[i][j].front().m << ' ';
        }cout<<endl;
    }cout<<endl;
}

void Print2()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(board[i][j].empty()) continue;
            cout << i << ',' << j << endl;
            for(auto x : board[i][j]) cout << x.m << ' ' << x.s << ' ' << x.d << endl;

        }cout<<endl;
    }cout<<endl;
}

// fireball의 이동, newBoard의 새로운 위치에 삽입
void MoveFireBall(Fireball fireball, vector<Fireball> newBoard[][52], int _r, int _c)
{
    int r = _r, c = _c;
    for(int i = 0; i < fireball.s; i++)
    {
        r = r + dr[fireball.d];
        c = c + dc[fireball.d];
        if(r == 0) r = N;
        if(r == N+1) r = 1;
        if(c == 0) c = N;
        if(c == N+1) c = 1;
    }
    newBoard[r][c].push_back(fireball);
}

void MoveAll()
{
    // 파이어볼들 이동 후 새로운 위치
    vector<Fireball> newBoard[52][52];
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            while(!board[r][c].empty())
            {
                MoveFireBall(board[r][c].back(), newBoard, r, c);
                board[r][c].pop_back();
            }
        }
    }
    // 이 시점에 board의 모든 칸들은 비어있을것

    // 2.
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(newBoard[r][c].empty()) continue;

            if(newBoard[r][c].size() == 1) // 1개의 파이어볼
            {
                board[r][c].push_back(newBoard[r][c].back());
                newBoard[r][c].pop_back();
            }
            else // 같은 칸에 2개 이상 파이어볼
            {
                int m = 0, s = 0, cnt = (int)newBoard[r][c].size();
                bool allSame = true;
                bool even = newBoard[r][c].back().d % 2 == 0;
                while(!newBoard[r][c].empty())
                {
                    m += newBoard[r][c].back().m;
                    s += newBoard[r][c].back().s;
                    // 홀짝 하나라도 다르면 allSame = false
                    bool even2 = newBoard[r][c].back().d % 2 == 0;
                    if(even != even2) allSame = false;
                    newBoard[r][c].pop_back();
                }

                m = floor(m / 5);
                s = floor(s / cnt);
                if(m == 0) continue; // 질량이 0인 파이어볼은 소멸

                if(allSame) // 0,2,4,6
                {
                    board[r][c].push_back({m, s, 0});
                    board[r][c].push_back({m, s, 2});
                    board[r][c].push_back({m, s, 4});
                    board[r][c].push_back({m, s, 6});
                }
                else
                {
                    board[r][c].push_back({m, s, 1});
                    board[r][c].push_back({m, s, 3});
                    board[r][c].push_back({m, s, 5});
                    board[r][c].push_back({m, s, 7});
                }
            }

        }
    }
}

int CountAnswer()
{
    int sum = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            while(!board[i][j].empty())
            {
                sum += board[i][j].back().m;
                board[i][j].pop_back();
            }
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({m, s, d});
    }



    for(int i = 0; i < K; i++) MoveAll();


    cout << CountAnswer();

}