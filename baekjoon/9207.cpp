#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R=5, C=9;
int pinN = 1;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

// idx 번 핀이 dir 방향으로 이동 가능한지
bool TryMove(int board[][9], int nr, int nc, int nnr, int nnc)
{
    if(nr < 0 || nr >= R || nc < 0 || nc >= C) return false;
    if(board[nr][nc] == -1 || board[nr][nc] == 0) return false;

    // 여기부터는 다음 좌표가 다른 핀인 경우
    if(nnr < 0 || nnr >= R || nnc < 0 || nnc >= C) return false;
    if(board[nnr][nnc] == 0 ) return true; // 핀을 넘은곳이 빈 공간인 경우 참 반환
    return false; // 외의 모든 경우 거짓
}

// idx번 핀 이동 시킴, midPin에 타고 넘은 핀의 번호 저장함
void Move(int board[][9], int idx, int r, int c, int nr, int nc, int nnr, int nnc, int &midPin, vector<pair<int,int>> &pins)
{
    midPin = board[nr][nc];
    board[r][c] = 0; // 핀의 원래 자리는 비워짐
    board[nnr][nnc] = idx; // 핀의 이동 자리
    board[nr][nc] = 0; // 핀이 넘은 핀, 사라짐

    pins[idx] = {nnr, nnc};
    pins[midPin] = {-1, -1};
}


// 복구 시킴
void Restore(int board[][9], int idx, int r, int c, int nr, int nc, int nnr, int nnc, int midPin, vector<pair<int,int>> &pins)
{
    board[r][c] = idx;
    board[nnr][nnc] = 0;
    board[nr][nc] = midPin;

    pins[idx] = {r, c};
    pins[midPin] = {nr, nc};
}

int ansPin = 100000000, ansDepth = 100000000;

// 핀을 order에 정해진 순서대로 이동시킴
void dfs(int board[][9], vector<pair<int,int>> &pins, int depth, int pinCnt)
{
    if(pinCnt < ansPin)
    {
        ansPin = pinCnt;
        ansDepth = depth;
    }

    for(int i = 1; i <= pinN; i++)
    {
        if(pins[i].first == -1) continue; // 사라진 핀 제외
        for(int dir = 0; dir < 4; dir++)
        {
            int r = pins[i].first, c = pins[i].second; // 현재 좌표
            int nr = r + dr[dir], nc = c + dc[dir]; // 다음 좌표
            int nnr = nr + dr[dir], nnc = nc + dc[dir]; // 핀을 넘어서 좌표
            int midPin=0; // 타고 넘은 핀 번호
            // 이동되는지 확인하고
            if(TryMove(board, nr, nc, nnr, nnc))
            {
                Move(board, i, r, c, nr, nc, nnr, nnc, midPin, pins); // 이동시킴
                dfs(board, pins, depth+1, pinCnt-1);
                // 복구시킴
                Restore(board, i, r, c, nr, nc, nnr, nnc, midPin, pins);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        pinN = 1;
        int board[5][9];
        // pins[1] = 1번 핀의 좌표
        vector<pair<int,int>> pins(1); // 핀들의 좌표, 1부터 시작

        for(int i = 0; i < R; i++)
        {
            for(int j = 0; j < C; j++)
            {
                char c; cin >> c;
                if(c == 'o') // pin
                {
                    pins.push_back({i,j});
                    board[i][j] = pinN++;
                }
                else if(c == '.') board[i][j] = 0; // .
                else board[i][j] = -1; // #
            }
        }
        pinN--;

        ansPin = 100000000, ansDepth = 100000000;
        dfs(board, pins, 0, pinN);
        cout << ansPin << ' ' << ansDepth << '\n';
    }


}