#include <iostream>
#include <vector>
using namespace std;

int N, M, x, y, K;
int board[21][21];
int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};

vector<int> RollDice(int dir, vector<int> diceIdx)
{
    vector<int> ret;
    switch(dir)
    {
        case 1:
            ret = {0, diceIdx[3], diceIdx[2], diceIdx[6], diceIdx[1], diceIdx[5], diceIdx[4]};
            return ret;

        case 2:
            ret = {0, diceIdx[4], diceIdx[2], diceIdx[1], diceIdx[6], diceIdx[5], diceIdx[3] };
            return ret;

        case 3:
            ret = {0, diceIdx[2], diceIdx[6], diceIdx[3], diceIdx[4], diceIdx[1], diceIdx[5] };
            return ret;

        case 4:
            ret = {0, diceIdx[5], diceIdx[1], diceIdx[3], diceIdx[4], diceIdx[6], diceIdx[2] };
            return ret;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 아랫면:1, 윗면:6
    vector<int>  diceIdx = {0, 1, 2, 3, 4, 5, 6};
    vector<int> dice = {0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < K; i++)
    {
        int dir; cin >> dir;
        int nx = x + dr[dir]; int ny = y + dc[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        x = nx; y = ny;
        diceIdx = RollDice(dir, diceIdx); // 주사위 굴린다

        // 이동한 칸이 0이면 주사위 바닥면을 칸에 복사
        if(board[x][y] == 0)
        {
            board[x][y] = dice[diceIdx[1]];
        }
        // 칸의 숫자를 주사위 바닥면에 복사, 칸에 쓰여있는 수는 0으로
        else
        {
            dice[diceIdx[1]] = board[x][y];
            board[x][y] = 0;
        }

        cout << dice[diceIdx[6]] << '\n';
    }


}