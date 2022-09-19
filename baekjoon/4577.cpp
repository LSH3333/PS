#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void Move(char _dir, pair<int,int> &wPos, vector<vector<char>> &board, const vector<vector<char>> &originalBoard)
{
    int dir;
    if(_dir == 'U') dir = 0;
    else if(_dir == 'R') dir = 1;
    else if(_dir == 'D') dir = 2;
    else dir = 3;

    int nr = wPos.first + dr[dir], nc = wPos.second + dc[dir];
    if(nr < 0 || nr >= N || nc < 0 || nc >= M) return;
    if(board[nr][nc] == '#') return;

    if(board[nr][nc] == '.')
    {
        board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
        board[nr][nc] = 'w';
        wPos.first = nr; wPos.second = nc;
    }
    else if(board[nr][nc] == '+')
    {
        board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
        board[nr][nc] = 'W';
        wPos.first = nr; wPos.second = nc;
    }
    else if(board[nr][nc] == 'b')
    {
        // 박스가 움직일수 있는 경우
        int nnr = nr + dr[dir], nnc = nc + dc[dir];
        if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= M) return;
        if(board[nnr][nnc] == '.') // 다다음이 빈 공간인 경우
        {
            board[nnr][nnc] = 'b';
            board[nr][nc] = 'w';
            board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
            wPos.first = nr; wPos.second = nc;
        }
        else if(board[nnr][nnc] == '+') // 다다음이 목표지점인 경우
        {
            board[nnr][nnc] = 'B';
            board[nr][nc] = 'w';
            board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
            wPos.first = nr; wPos.second = nc;
        }
    }
    else if(board[nr][nc] == 'B')
    {
        int nnr = nr + dr[dir], nnc = nc + dc[dir];
        if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= M) return;
        if(board[nnr][nnc] == '.')
        {
            board[nnr][nnc] = 'b';
            board[nr][nc] = 'W';
            board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
            wPos.first = nr; wPos.second = nc;
        }
        else if(board[nnr][nnc] == '+')
        {
            board[nnr][nnc] = 'B';
            board[nr][nc] = 'W';
            board[wPos.first][wPos.second] = originalBoard[wPos.first][wPos.second];
            wPos.first = nr; wPos.second = nc;
        }
    }
}

void PrintBoard(const vector<vector<char>> &board)
{
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cout << board[r][c];
        } cout << '\n';
    }
}

bool IsGameOver(const vector<vector<char>> &board)
{
    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            if(board[r][c] == 'b') return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int gameCnt = 1;
    while(true)
    {
        cin >> N >> M;
        if(N == 0 && M == 0) break;

        vector<vector<char>> board(20, vector<char>(20));
        // 캐릭터, 박스 없을때의 보드판
        vector<vector<char>> originalBoard(20, vector<char>(20));
        string movement;
        pair<int,int> wPos;

        for(int r = 0; r < N; r++)
        {
            string temp; cin >> temp;
            for(int c = 0; c < M; c++)
            {
                board[r][c] = temp[c];
                if(board[r][c] == 'w' || board[r][c] == 'W') { wPos = {r, c}; }

                originalBoard[r][c] = board[r][c];
                if(originalBoard[r][c] == 'b' || originalBoard[r][c] == 'w') originalBoard[r][c] = '.';
                else if(originalBoard[r][c] == 'B' || originalBoard[r][c] == 'W') originalBoard[r][c] = '+';
            }
        }
        cin >> movement;


        bool complete = false;
        for(auto dir : movement)
        {
            if(IsGameOver(board)) { complete = true; break; }
            Move(dir, wPos, board, originalBoard);
        }

        if(complete) cout << "Game " << gameCnt << ": " << "complete\n";
        else cout << "Game " << gameCnt++ << ": " << "incomplete\n";
        PrintBoard(board);

    }


}