#include <iostream>
#include <deque>
using namespace std;

#define SNAKE 1
#define APPLE 2

#define LEFT 1
#define RIGHT 2

int N, K, L;
int board[110][110];
int timeStamp[10010]; // timeStamp[i]=LEFT ? i ?? LEFT ? ?? ??
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

struct Snake {
    // front:head, back:tail
    deque<pair<int,int>> body;
    int dir;
};

void Print(int sec) {
    cout << "sec: " << sec << endl;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << board[i][j] << ' ';
        }cout<<endl;
    }cout<<endl;
}

bool proceed(Snake &snake) {
    int nr = snake.body.front().first + dr[snake.dir];
    int nc = snake.body.front().second + dc[snake.dir];

    // ??? ????? ?? ??? ??
    if(nr <= 0 || nr > N || nc <= 0 || nc > N || board[nr][nc] == SNAKE) {
        return false;
    }
        // ??? ?? ??? ???
    else if(board[nr][nc] == APPLE) {
        board[nr][nc] = SNAKE;
        snake.body.push_front({nr, nc});
    }
        // ??? ?? ??? ???
    else {
        board[nr][nc] = SNAKE;
        snake.body.push_front({nr, nc});
        board[snake.body.back().first][snake.body.back().second] = 0;
        snake.body.pop_back();
    }
    return true;
}

int GetDir(int curDir, int turnDir) {
    if(turnDir == LEFT) {
        if(curDir == 0) return 3;
        else return curDir-1;
    }
    else {
        return (curDir + 1) % 4;
    }
}

int Game(Snake &snake) {
    int sec = 0;
    while(true) {
//        Print(sec);

        bool res = proceed(snake);
        sec++;
        if(!res) {
            return sec;
        }

        // ?? ?? ??? ??
        if(timeStamp[sec] == LEFT) {
            snake.dir = GetDir(snake.dir, LEFT);
        }
        else if(timeStamp[sec] == RIGHT){
            snake.dir = GetDir(snake.dir, RIGHT);
        }

    }
}



int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int r,c; cin >> r >> c;
        board[r][c] = APPLE;
    }
    cin >> L;
    for(int i = 0; i < L; i++) {
        int X; char C;
        cin >> X >> C;
        if(C == 'L') timeStamp[X] = LEFT;
        else timeStamp[X] = RIGHT;
    }

    Snake snake{{{1, 1}},1};
    board[1][1] = SNAKE;

    cout << Game(snake);

}