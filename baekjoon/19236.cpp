#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

int answer;

class Fish
{
public:
    int num;
    int dir;
    int r;
    int c;
    Fish(int _num, int _dir, int _r, int _c): num(_num), dir(_dir), r(_r), c(_c) {}
};

class Shark
{
public:
    int r;
    int c;
    int dir;
    Shark(int _r, int _c, int _dir) : r(_r), c(_c), dir(_dir) {}
};

void Print(const vector<Fish> &loc, const Shark& shark, const vector<vector<int>> &board)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == -2) cout << board[i][j] << ',' << shark.dir << ' '; // 상어
            else
            {
                if(loc[board[i][j]].num == -1) cout << 0 << ',' << 0 << ' '; // 빈 공간
                else cout << board[i][j] << ',' << loc[board[i][j]].dir << ' ';
            }
        } cout << endl;
    } cout << endl;
}

void MoveFish(Fish &fish, Shark &shark, vector<Fish> &loc, vector<vector<int>> &board)
{
    int dir = fish.dir;
    for(int i = 0; i < 8; i++, dir = (dir+1)%8)
    {
        int nr = fish.r + dr[dir];
        int nc = fish.c + dc[dir];

        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
        if(board[nr][nc] == -2) continue; // shark

        // 이동, 자리 바꿈
        Fish cur(fish.num, dir, fish.r, fish.c);
        Fish target(loc[board[nr][nc]].num, loc[board[nr][nc]].dir, loc[board[nr][nc]].r, loc[board[nr][nc]].c);
        // 위치 정보 swap
        loc[cur.num] = {cur.num, cur.dir, target.r, target.c};
        loc[target.num] = {target.num, target.dir, cur.r, cur.c};

        board[cur.r][cur.c] = board[nr][nc];
        board[nr][nc] = cur.num;

        break;
    }
}

// 모든 물고기들의 이동
void MoveAllFishes(vector<Fish> &loc, Shark &shark, vector<vector<int>> &board)
{
    for(int i = 1; i <= 16; i++)
    {
        if(loc[i].num == -1) continue; // 잡아 먹힌 물고기
        MoveFish(loc[i], shark, loc, board);
    }
}

// board[r][c]의 물고기를 먹음, 먹은 물고기의 수 리턴
int EatFish(Shark &shark, vector<Fish> &loc, int r, int c, vector<vector<int>> &board)
{
    int ate = board[r][c];
    Shark before = shark;
    // 상어 이동
    board[r][c] = -2;
    shark.r = r; shark.c = c;
    shark.dir = loc[ate].dir;
    // 먹힌 물고기 처리
    loc[ate].num = -1; loc[ate].dir = -1; loc[ate].r = -1; loc[ate].c = -1;
    board[before.r][before.c] = 0;

    return ate;
}

void dfs(Shark &shark, vector<Fish> &loc, int ate, vector<vector<int>> &board)
{
    answer = max(answer, ate);
    // back up
    Shark restoreShark = shark;
    vector<vector<int>> resBoard = board;
    vector<Fish> restoreLoc = loc;

    cout << "ate: " << ate << endl;
    Print(loc, shark, board);

    int r = shark.r, c = shark.c;
    for(int i = 0; i <= 3; i++)
    {
        r = r + dr[shark.dir];
        c = c + dc[shark.dir];
        if(r < 0 || r >= 4 || c < 0 || c >= 4) break;
        if(board[r][c] == 0) continue;

        int amount = EatFish(shark, loc, r, c, board);
        MoveAllFishes(loc, shark, board);
        dfs(shark, loc, ate+amount, board);

        shark = restoreShark;
        resBoard = board;
        loc = restoreLoc;
    }
}

int main()
{
    // 물고기들의 위치
    vector<Fish> loc(17, {-1,-1,-1,-1});
    vector<vector<int>> board(4, vector<int>(4,0));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int num, dir; cin >> num >> dir;
            board[i][j] = num;
            loc[num] = Fish(num, dir-1, i, j);
        }
    }
    loc[0] = {0, 0, 0, 0};


    int firstFish = board[0][0];
    Shark shark(0,0,0);
    // (0,0)에 상어 투입
    shark.dir = loc[firstFish].dir;
    loc[board[0][0]] = {-1,-1,-1,-1};
    board[0][0] = -2;

    MoveAllFishes(loc, shark, board);
    Print(loc, shark, board);

    dfs(shark, loc, firstFish, board);

    cout << answer;
}