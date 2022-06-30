#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<char> board[101][101];

struct Pos
{
    int r, c;
};

void Print()
{
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(board[i][j].empty()) cout << '.';
            else cout << board[i][j].front();
        } cout << '\n';
    }
}

int dr[] = {0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
int dc[] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};

// I를 이동 시킨다
// I가 아두이노 칸으로 이동하여 게임이 끝났다면 false return
// 아니라면 I 이동 시킨 후 return true
bool MoveI(int dir, Pos &IPos)
{
    if(dir == 5) return true; // dir=5면 이동 없음
    int nr = IPos.r + dr[dir];
    int nc = IPos.c + dc[dir];
    if(!board[nr][nc].empty() && board[nr][nc].front() == 'R') {return false; }
    board[nr][nc].push_back('I');
    board[IPos.r][IPos.c].clear();
    IPos.r = nr; IPos.c = nc;
    return true;
}

// R의 다음 위치 찾음
// nextPos에 다음 위치 저장함
// 다음 위치에 I가 있으면 게임 종료이므로 return false
bool FindRDir(const Pos &IPos, int Rr, int Rc, vector<Pos> &nextPos)
{
    int Ir = IPos.r, Ic = IPos.c;
    int minDist = 1000000;
    int nextR, nextC;
    // 거리가 가장 가까워지는 좌표 찾음
    for(int dir = 1; dir <= 9; dir++)
    {
        if(dir == 5) continue;
        int nr = Rr + dr[dir];
        int nc = Rc + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        int dist = abs(Ir-nr) + abs(Ic-nc);
        if(dist < minDist) {minDist = dist; nextR = nr; nextC = nc;}
    }

    if(!board[nextR][nextC].empty() && board[nextR][nextC].front() == 'I') { return false; }// 이동하는 위치에 I가 있음
    nextPos.push_back({nextR, nextC});
    return true;
}

// 모든 아두이노들 이동 시킴, 만약 겹치는 아두이노 있다면 제거함
// 게임 종료라면 return false
bool MoveR(Pos &IPos)
{
    vector<Pos> nextPos;
    for(int r = 0; r < R; r++)
    {
        for(int c = 0; c < C; c++)
        {
            if(board[r][c].empty()) continue;
            if(board[r][c].front() != 'R') continue;

            if(!FindRDir(IPos, r, c, nextPos)) return false;
        }
    }

    // nextPos에 저장된 R의 다음 위치들 적용
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            board[i][j].clear();
        }
    }

    board[IPos.r][IPos.c].push_back('I');
    for(auto x : nextPos)
    {
        int r = x.r, c = x.c;
        board[r][c].push_back('R');
    }
    // 2개 이상 같은 위치인 아두이노 제거
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            if(board[i][j].size() >= 2) board[i][j].clear();
        }
    }

    return true;
}

// 게임 지는 경우 return false
bool OneTurn(int dir, Pos &IPos)
{
    if(!MoveI(dir, IPos)) return false;
    if(!MoveR(IPos)) return false;
    return true;
}

int main()
{
    cin >> R >> C;
    Pos IPos{0,0}; // I의 위치
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            char tmp; cin >> tmp;
            if(tmp == '.') continue;
            board[i][j].push_back(tmp);
            if(tmp == 'I') IPos = {i, j};
        }
    }

    queue<int> Dir; // I의 이동 방향
    string _s; cin >> _s;
    for(auto x : _s) Dir.push(x-'0');

    int cnt = 0;
    while(!Dir.empty())
    {
        cnt++;
        int dir = Dir.front();
        Dir.pop();
        // false시 게임 패배
        if(!OneTurn(dir, IPos))
        {
            cout << "kraj " << cnt << '\n';
            return 0;
        }
    }

    Print();
}