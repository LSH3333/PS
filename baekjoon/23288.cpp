#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define U 0
#define R 1
#define D 2
#define L 3

int N, M;
int board[22][22];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


struct Dice
{
    // 아래, 위, 앞, 뒤, 왼, 오
    vector<int> diceNum;
    int dir;
    int r;
    int c;
};

int CalScore(const Dice &dice)
{
    vector<vector<bool>> visited(N+2, vector<bool>(M+2, false));
    // r, c
    queue<pair<int,int>> q;
    visited[dice.r][dice.c] = true;
    q.push({dice.r, dice.c});
    int cnt = 1;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
            if(visited[nr][nc] || board[nr][nc] != board[dice.r][dice.c]) continue;
            q.push({nr,nc});
            visited[nr][nc] = true;
            cnt++;
        }
    }
//    cout << "cnt: " << cnt << endl;
//    cout << dice.r << ',' << dice.c << endl;
    return cnt * board[dice.r][dice.c];
}

// 주사위를 dir 방향으로 움직인다
// diceNum, 좌표는 움직인 결과에 맞게 변경된다
void MoveDice(Dice &dice)
{
    vector<int> newDiceNum = {0,0,0,0,0,0,0};
    switch(dice.dir)
    {
        case U:
            newDiceNum = {0, dice.diceNum[2], dice.diceNum[6], dice.diceNum[3], dice.diceNum[4], dice.diceNum[1], dice.diceNum[5] };
            break;
        case R:
            newDiceNum = {0, dice.diceNum[4], dice.diceNum[2], dice.diceNum[1], dice.diceNum[6], dice.diceNum[5], dice.diceNum[3] };
            break;
        case D:
            newDiceNum = {0, dice.diceNum[5], dice.diceNum[1], dice.diceNum[3], dice.diceNum[4], dice.diceNum[6], dice.diceNum[2] };
            break;
        case L:
            newDiceNum = {0, dice.diceNum[3], dice.diceNum[2], dice.diceNum[6], dice.diceNum[1], dice.diceNum[5], dice.diceNum[4] };
            break;
        default:
            break;
    }

    dice.r = dice.r + dr[dice.dir];
    dice.c = dice.c + dc[dice.dir];
    dice.diceNum = newDiceNum;
}

// 주사위를 회전시킨다.
// clockwise == true 라면 시계방향
void RotateDir(Dice &dice, bool clockwise)
{
    if(clockwise)
    {
        if(dice.dir == U) dice.dir = R;
        else if(dice.dir == R) dice.dir = D;
        else if(dice.dir == D) dice.dir = L;
        else dice.dir = U;
    }
    else
    {
        if(dice.dir == U) dice.dir = L;
        else if(dice.dir == R) dice.dir = U;
        else if(dice.dir == D) dice.dir = R;
        else dice.dir = D;
    }
}

void MoveOnce(Dice &dice, int &score)
{
    int nr = dice.r + dr[dice.dir];
    int nc = dice.c + dc[dice.dir];
    // 이동 방향에 칸이 없다면 반대로
    if(nr <= 0 || nr > N || nc <= 0 || nc > M)
    {
        // 90도로 두번이면 180도
        RotateDir(dice, true);
        RotateDir(dice, true);
    }
    // 방향 정해졌으니 주사위 움직임
    MoveDice(dice);
    // 점수 계산
    score += CalScore(dice);

    // 이동 방향 결정
    int A = dice.diceNum[6];
    int B = board[dice.r][dice.c];
    if(A > B) RotateDir(dice, true);
    else if(A < B) RotateDir(dice, false);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int K;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 최초의 주사위 상태
    Dice dice;
    dice.diceNum = {0, 1, 2, 3, 4, 5, 6};
    dice.dir = R;
    dice.r = 1; dice.c = 1;
    int score = 0;

    while(K--)
    {
        MoveOnce(dice, score);
        cout << "score: " << score << endl;
        cout << dice.dir << ' ' << dice.r << ',' << dice.c << endl;
        for(auto x : dice.diceNum) cout << x << ' '; cout << endl << endl;
    }
    cout << score;
}