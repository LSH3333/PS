#include <iostream>
#include <vector>
using namespace std;

struct Robot
{
    int r;
    int c;
    int dir;
};

int A, B; // 가로, 세로
int N, M; // 로봇 수, 명령 수
int board[110][110];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// num 로봇이 F 명령 한번 수행 했을 때의 좌표 리턴
pair<int,int> OrderF(int num, vector<Robot> &robots)
{
    int nr = robots[num].r + dr[robots[num].dir];
    int nc = robots[num].c + dc[robots[num].dir];
    return {nr, nc};
}

void OrderL(int num, vector<Robot> &robots)
{
    int dir = robots[num].dir;
    dir = dir - 1;
    if(dir == -1) dir = 3;
    robots[num].dir = dir;
}

void OrderR(int num, vector<Robot> &robots)
{
    int dir = robots[num].dir;
    dir = (dir + 1) % 4;
    robots[num].dir = dir;
}


// 에러 발생시 문장 출력 후 리턴 false
// 에러 없을시 리턴 true
bool CheckError(int num, int r, int c)
{
    if(r < 1 || r > B || c < 1 || c > A) // crash wall error
    {
        cout << "Robot " << num << " crashes into the wall";
        return false;
    }
    if(board[r][c] != 0) // crash into robot error
    {
        cout << "Robot " << num << " crashes into robot " << board[r][c];
        return false;
    }
    return true;
}

void UpdateRobot(int num, int r, int c, int dir, vector<Robot> &robots)
{
    board[robots[num].r][robots[num].c] = 0;
    robots[num].r = r;
    robots[num].c = c;
    robots[num].dir = dir;
    board[r][c] = num;
}

// 명령 로봇, 명령 종류, 명령 반복 횟수
// 에러 발생시 리턴 false
bool MoveRobot(int num, char order, int cnt, vector<Robot> &robots)
{
    int dir = robots[num].dir;

    if(order == 'F')
    {
        for(int i = 0; i < cnt; i++)
        {
            pair<int,int> rc = OrderF(num, robots);
            int r = rc.first; int c = rc.second;
            if(!CheckError(num, r, c)) return false; // 에러 발생시 false return
            // 에러 없을시 로봇 상태 업데이트
            UpdateRobot(num, r, c, dir, robots);
        }
    }
    else if(order == 'L')
    {
        for(int i = 0; i < cnt; i++)
        {
            OrderL(num, robots);
        }
    }
    else // R
    {
        for(int i = 0; i < cnt; i++)
        {
            OrderR(num, robots);
        }
    }
    return true;
}

int main()
{
    cin >> A >> B >> N >> M;
    vector<Robot> robots(N+1);
    for(int i = 1; i <= N; i++)
    {
        int r, c; char d; int dir;
        cin >> c >> r >> d;
        if(d == 'N') dir = 0;
        else if(d == 'E') dir = 1;
        else if(d == 'S') dir = 2;
        else dir = 3;
        Robot robot{B-r+1, c, dir};
        robots[i] = robot;
        board[B-r+1][c] = i;
    }
    
    for(int i = 1; i <= M; i++)
    {
        int num, cnt; char order;
        cin >> num >> order >> cnt;
        if(!MoveRobot(num, order, cnt, robots)) return 0;
    }
    cout << "OK";
}