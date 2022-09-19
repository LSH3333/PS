#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool IsItPossible(int len, int r, int c, vector<vector<char>> &board)
{
    if(board[r][c] != '#') return false;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= len; j++)
        {
            int nr = r + (dr[i] * j);
            int nc = c + (dc[i] * j);
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
            if(board[nr][nc] != '#') return false;
        }
    }
    return true;
}

void Fill(int len, int r, int c, vector<vector<char>> &board)
{
    board[r][c] = '*'; // 십자가로 채워짐
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j <= len; j++)
        {
            int nr = r + (dr[i] * j);
            int nc = c + (dc[i] * j);
            board[nr][nc] = '*';
        }
    }
}

int Find(int len, vector<vector<char>> &board)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 십자가 자리 찾음
            if(IsItPossible(len, i, j, board))
            {
                Fill(len, i, j, board);
                return len * 4 + 1;
            }
        }
    }
    return -1; // 못찾음
}

int Cal(int len1, int len2, vector<vector<char>> &board)
{
    int size1 = Find(len1, board);
    if(size1 == -1) return 0;
    int size2 = Find(len2, board);
    if(size2 == -1) return 0;
    return size1 * size2;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    vector<vector<char>> original(N, vector<char>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> original[i][j];
        }
    }


    int answer = 0;
    for(int i = 0; i <= 7; i++)
    {
        for(int j = 0; j <= 7; j++)
        {
            vector<vector<char>> board = original;
            answer = max(answer, Cal(i, j, board));
        }
    }
    cout << answer;
}