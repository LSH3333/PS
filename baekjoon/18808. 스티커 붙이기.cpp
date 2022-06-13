#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

// board의 [_r][_c] 부터 스티커 맞춰봄
// 스티커 부착 가능하면 return true else false
bool Fit(vector<vector<int>> &board, vector<vector<int>> &sticker, int _r, int _c)
{
    int R = (int)sticker.size();
    int C = (int)sticker.front().size();

    for(int r = _r; r < _r+R; r++)
    {
        for(int c = _c; c <_c+C; c++)
        {
            if(sticker[r-_r][c-_c] == 0) continue;
            if(board[r][c] == 1) return false;
        }
    }
    return true;
}

// board[_r][_c] 부터 스티커 부착함
void PutSticker(vector<vector<int>> &board, vector<vector<int>> &sticker, int _r, int _c)
{
    int R = (int)sticker.size(); // 스티커 세로 길이
    int C = (int)sticker.front().size(); // 스티커 가로 길이

    for(int r = _r; r < _r+R; r++)
    {
        for(int c = _c; c <_c+C; c++)
        {
            if(sticker[r-_r][c-_c] == 0) continue;
            board[r][c] = 1;
        }
    }
}

// 스티커 부착 가능 지점, 열 행 순으로 이동하며 탐색
// 스티커 부착 성공했다면 return true else false
bool FindStickerStartPos(vector<vector<int>> &board, vector<vector<int>> &sticker)
{
    int R = (int)sticker.size();
    int C = (int)sticker.front().size();

    for(int r = 0; r <= N-R; r++)
    {
        for(int c = 0; c <= M-C; c++)
        {
            if(Fit(board, sticker, r, c))
            {
                PutSticker(board, sticker, r, c);
                return true;
            }
        }
    }
    return false;
}

// 스티커 90도 시계 방향 회전
// 새로운 스티커 리턴
vector<vector<int>> Rotate(vector<vector<int>> &sticker)
{
    int R = (int)sticker.size();
    int C = (int)sticker.front().size();

    vector<vector<int>> newSticker(C, vector<int>(R,0));
    int RR = (int)newSticker.size();
    int RC = (int)newSticker.front().size();

    int cnt = 1;
    for(int r = 0; r < R; r++)
    {
        int ccnt = 0;
        for(int c = 0; c < C; c++)
        {
            newSticker[ccnt][RC-cnt] = sticker[r][c];
            ccnt++;
        }
        cnt++;
    }

    return newSticker;
}

void Print(const vector<vector<int>> &arr)
{
    for(int i = 0; i < (int)arr.size(); i++)
    {
        for(int j = 0; j < (int)arr.front().size(); j++)
        {
            cout << arr[i][j] << ' ';
        } cout << endl;
    } cout << endl;

}



int main()
{
    cin >> N >> M >> K;
    vector<vector<int>> board(N, vector<int>(M, 0));
    for(int i = 0; i < K; i++)
    {
        int R, C; cin >> R >> C;
        vector<vector<int>> sticker(R, vector<int>(C,0));
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++)
            {
                cin >> sticker[r][c];
            }
        }

        for(int dir = 0; dir < 4; dir++)
        {
            // 스티커 위치 찾았다면 회전 불필요
            if(FindStickerStartPos(board, sticker)) break;
            sticker = Rotate(sticker); // 90도 회전
        }
    }

    //
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            answer += board[i][j];
        }
    }
    cout << answer;

}