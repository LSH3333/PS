#include <iostream>
#include <vector>
using namespace std;

struct Block
{
    int t;
    int r1, c1;
    int r2, c2;
};

#define R 0
#define D 1

int answer;
// R, D
int dr[] = {0, 1};
int dc[] = {1, 0};

// 해당 방향으로 한 칸 이동, 다음으로 이동할 곳이 옳지 않으면 이동하지 않고 false return
bool MoveOnce(int dir, Block &block, vector<vector<bool>> &board)
{
    if((dir == D && block.t == 3) || (dir == R && block.t == 2))
    {
        int nr2 = block.r2 + dr[dir], nc2 = block.c2 + dc[dir];
        if(nr2 > 9 || nc2 > 9) return false;
        if(board[nr2][nc2]) return false;

        board[block.r1][block.c1] = false;
        board[nr2][nc2] = true;

        block.r1 = block.r2; block.c1 = block.c2;
        block.r2 = nr2; block.c2 = nc2;
        return true;
    }
    else
    {
        int nr1 = block.r1 + dr[dir], nc1 = block.c1 + dc[dir];
        int nr2 = block.r2 + dr[dir], nc2 = block.c2 + dc[dir];
        if(nr1 > 9 || nc1 > 9 || nr2 > 9 || nc2 > 9) return false;
        if(board[nr1][nc1]) return false;
        if(block.t >= 2 && board[nr2][nc2]) return false;

        board[block.r1][block.c1] = false;
        board[nr1][nc1] = true;
        if(block.t >= 2) { board[block.r2][block.c2] = false; board[nr2][nc2] = true; }
        block.r1 = nr1; block.c1 = nc1;
        if(block.t >= 2) { block.r2 = nr2; block.c2 = nc2; }
        return true;
    }
}

// 빨강색 타일에 블록을 놓는다
void PutBlockOnRed(vector<vector<bool>> &board, Block &block)
{
    Block initBlock = block;
    while(MoveOnce(D, block, board));
    block = initBlock;
    while(MoveOnce(R, block, board));
}

// dir 방향으로, idx 위 or 왼쪽 블록들이 한칸씩 이동
void MoveRowCol(vector<vector<bool>> &board, int dir, int idx)
{
    if(dir == D)
    {
        // DOWN
        // r행이 r+1행으로 이동
        for(int r = idx-1; r >= 4; r--)
        {
            for(int c = 0; c < 4; c++)
            {
                board[r+1][c] = board[r][c];
                board[r][c] = false;
            }
        }
    }
    else
    {
        // RIGHT
        // c열이 c+1열로 이동
        for(int c = idx-1; c >= 4; c--)
        {
            for(int r = 0; r < 4; r++)
            {
                board[r][c+1] = board[r][c];
                board[r][c] = false;
            }
        }
    }


}

// 행열 완성된곳 찾아서 지움
void Erase(vector<vector<bool>> &board)
{
    bool found = false;
    // Green area
    while(true)
    {
        found = false;
        for(int r = 9; r >= 6; r--)
        {
            int cnt = 0;
            for(int c = 0; c < 4; c++)
                if(board[r][c]) cnt++;
            // 한줄 완성
            if(cnt == 4)
            {
                answer++;
                MoveRowCol(board, D, r);
                found = true;
                break;
            }
        }
        if(!found) break;
    }

    // Blue area
    while(true)
    {
        found = false;
        for(int c = 9; c >= 6; c--)
        {
            int cnt = 0;
            for(int r = 0; r < 4; r++)
                if(board[r][c]) cnt++;
            // 한줄 완성
            if(cnt == 4)
            {
                answer++;
                MoveRowCol(board, R, c);
                found = true;
                break;
            }
        }
        if(!found) break;
    }
}

// 연한 부분 처리
void SoftColorArea(vector<vector<bool>> &board)
{
    // Green area
    int cnt = 0;
    for(int r = 4; r <= 5; r++)
    {
        for(int c = 0; c < 4; c++)
        {
            if(board[r][c]) { cnt++; break; }
        }
    }
    for(int i = 0; i < cnt; i++) MoveRowCol(board, D, 9);

    // Blue area
    cnt = 0;
    for(int c = 4; c <= 5; c++)
    {
        for(int r = 0; r < 4; r++)
        {
            if(board[r][c]) { cnt++; break;}
        }
    }
    for(int i = 0; i < cnt; i++) MoveRowCol(board, R, 9);
}

void CalOneBlock(vector<vector<bool>> &board, Block &block)
{
    PutBlockOnRed(board, block);
    Erase(board);
    SoftColorArea(board);
}

void Print(const vector<vector<bool>> &board)
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i > 3 && j > 3) continue;
            cout << board[i][j];
        } cout << endl;
    }cout<<endl;
}

int CountTiles(const vector<vector<bool>> &board)
{
    int cnt = 0;
    for(int r = 6; r < 10; r++)
    {
        for(int c = 0; c < 4; c++)
        {
            if(board[r][c]) cnt++;
            if(board[c][r]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<vector<bool>> board(10, vector<bool>(10, false));
    while(N--)
    {
        int t, r, c; cin >> t >> r >> c;
        Block block;
        if(t == 1)
            block = {t, r, c, 0, 0};
        else if(t == 2)
            block = {t, r, c, r, c+1};
        else
            block = {t, r, c, r+1, c};

        CalOneBlock(board, block);
//        Print(board);
    }

    cout << answer << '\n';
    cout << CountTiles(board);
}