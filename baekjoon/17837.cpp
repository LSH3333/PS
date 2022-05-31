#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WHITE 0
#define RED 1
#define BLUE 2

// right, left, up, down
int dr[] = {0, 0, -1, 1};
int dc[] = {1, -1, 0, 0};
int N, K;
int color[15][15];

struct Piece
{
    int r; // 말의 위치 행
    int c; // 열
    int h; // 높이
    int dir; // 방향
};

Piece pieces[15];

int OppositeDir(int dir)
{
    if(dir == 0) return 1;
    if(dir == 1) return 0;
    if(dir == 2) return 3;
    if(dir == 3) return 2;
    return 0;
}

// pieces[] 정보 업데이트
// _h는 아래 있는 말들의 갯수
void Update(const vector<int> &movingPieces, int nr, int nc, int _h)
{
    for(int i = 0; i < movingPieces.size(); i++)
    {
        int p = movingPieces[i];
        pieces[p].r = nr;
        pieces[p].c = nc;
        pieces[p].h = _h + i;
    }
}

int MovePiece(int num, vector<int> board[][15])
{
    int r = pieces[num].r, c = pieces[num].c, h = pieces[num].h, dir = pieces[num].dir;

    int nr = r + dr[dir];
    int nc = c + dc[dir];

    // 이번에 움직이게될 말들
    vector<int> movingPieces(board[r][c].begin()+h, board[r][c].end());
    board[r][c].erase(board[r][c].begin()+h, board[r][c].end());

    // BLUE
    if(nr < 1 || nr > N || nc < 1 || nc > N || color[nr][nc] == BLUE)
    {
        // 방향 반대로 하고 이동
        dir = OppositeDir(dir); pieces[num].dir = dir;
        nr = r + dr[dir]; nc = c + dc[dir];

        // 방향 바꾸고 이동
        // BLUE면 그대로
        if(nr < 1 || nr > N || nc < 1 || nc > N || color[nr][nc] == BLUE)
        {
            for(auto p : movingPieces) board[r][c].push_back(p);
            return (int)board[r][c].size();
        }
        else if(color[nr][nc] == RED) // RED
        {
            int _h = (int)board[nr][nc].size();
            reverse(movingPieces.begin(), movingPieces.end());
            for(auto p : movingPieces) board[nr][nc].push_back(p);
            Update(movingPieces, nr, nc, _h);
            return (int)board[nr][nc].size();
        }
        else // WHITE
        {
            int _h = (int)board[nr][nc].size();
            for(auto p : movingPieces) board[nr][nc].push_back(p);
            Update(movingPieces, nr, nc, _h);
            return (int)board[nr][nc].size();
        }
    }

    // WHITE
    if(color[nr][nc] == WHITE)
    {
        int _h = (int)board[nr][nc].size();
        for(auto p : movingPieces) board[nr][nc].push_back(p);
        Update(movingPieces, nr, nc, _h);
        return (int)board[nr][nc].size();
    }

    // RED
    if(color[nr][nc] == RED)
    {
        int _h = (int)board[nr][nc].size();
        reverse(movingPieces.begin(), movingPieces.end());
        for(auto p : movingPieces) board[nr][nc].push_back(p);
        Update(movingPieces, nr, nc, _h);
        return (int)board[nr][nc].size();
    }
    return 0;
}

// 1번 부터 K번까지의 말 움직임
// 게임 종료되면 false 리턴
bool MoveAll(vector<int> board[][15])
{
    for(int i = 1; i <= K; i++)
    {
        if(MovePiece(i, board) >= 4) return false;
    }

    return true;
}

void Print(vector<int> board[][15])
{
    cout << "-----------------\n";
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << i << ',' << j << ": ";
            if(!board[i][j].empty()) for(auto x : board[i][j]) cout << x << ' ';
            cout << endl;
        } cout << endl;
    } cout << endl;

    for(int i = 1; i <= K; i++)
    {
        cout << i << ": " << pieces[i].r << ", " << pieces[i].c << ", " << pieces[i].h << ", " << pieces[i].dir << endl;
    }
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> color[i][j];
        }
    }

    vector<int> board[15][15];
    for(int i = 1; i <= K; i++)
    {
        int r, c, dir; cin >> r >> c >> dir;
        pieces[i].r = r;
        pieces[i].c = c;
        pieces[i].h = 0;
        pieces[i].dir = dir-1;
        board[r][c].push_back(i);
    }

    int turn = 1;
    while(true)
    {
        if(turn > 1000) break;
        if(!MoveAll(board))
        {
            break;
        }
        turn++;
    }
    if(turn > 1000) cout << -1;
    else cout << turn;

}