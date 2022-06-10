#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


void Print(vector<vector<int>> &board)
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            printf("%2d ", board[i][j]);
        } cout << endl;
    } cout << endl;
}

// 시작점 (_r,_c)에서 부터 한 변 크기 _l의 정사각형 회전 시킴
void Rotate(int _r, int _c, int l, vector<vector<int>> &board)
{
    vector<vector<int>> newBoard(l+1, vector<int>(l+1));
    for(int r = _r; r < _r+l; r++)
    {
        for(int c = _c; c < _c+l; c++)
        {
            newBoard[r-_r+1][c-_c+1] = board[r][c];
        }
    }

    int ccnt = 1;
    for(int r = _r; r < _r+l; r++)
    {
        int cnt = 0;
        for(int c = _c; c < _c+l; c++)
        {
            board[r][c] = newBoard[l-cnt][ccnt];
            cnt++;
        }
        ccnt++;
    }


}

// L 값에 따라 board 회전 시킴
void RotateL(int _l, vector<vector<int>> &board)
{
    int l =(int) pow(2, _l);

    for(int r = 1; r <= N; r+=l)
    {
        for(int c = 1; c <= N; c+=l)
        {
            Rotate(r, c, l, board);
        }
    }
}

// board의 녹아야할 얼음 녹임 (1 줄임)
void Melt(vector<vector<int>> &board)
{
    vector<vector<int>> newBoard = board;

    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            if(board[r][c] <= 0) continue;
            int cnt = 0; // 인접한 얼음 없는 칸 수
            for(int dir = 0; dir < 4; dir++)
            {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if(nr < 1 || nr > N || nc < 1 || nc > N || board[nr][nc] <= 0) cnt++;
            }
            // melt
            if(cnt >= 2) newBoard[r][c]--; // newBoard의 얼음 녹임
        }
    }

    board = newBoard;
}

// 한 덩어리의 칸 갯수 리턴
int bfs(int _r, int _c, vector<vector<bool>> &mark, const vector<vector<int>> &board)
{
    queue<pair<int,int>> q;
    mark[_r][_c] = true;
    q.push({_r,_c});
    int ret = 1;

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(board[nr][nc] <= 0 || mark[nr][nc]) continue;
            mark[nr][nc] = true;
            q.push({nr,nc});
            ret++;
        }
    }
    return ret;
}

// 남아있는 얼음의 합, 가장 큰 덩어리의 칸 갯수 리턴
pair<int,int> CountChunk(vector<vector<int>> &board)
{
    vector<vector<bool>> mark(N+1, vector<bool>(N+1, false));
    int cnt = 0;
    int maxN = 0;
    for(int r = 1; r <= N; r++)
    {
        for(int c = 1; c <= N; c++)
        {
            cnt += board[r][c];
            if(board[r][c] <= 0 || mark[r][c]) continue;
            maxN = max(maxN, bfs(r, c, mark, board));
        }
    }
    return {cnt, maxN};
}

int main()
{
    cin >> N >> Q;
    N = (int)pow(2, N);
    vector<vector<int>> board(N+1, vector<int>(N+1));
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < Q; i++)
    {
        int l; cin >> l;
        RotateL(l, board); // 회전 시키고
        Melt(board);
    }

    pair<int,int> answer = CountChunk(board);
    cout << answer.first << '\n' << answer.second;

}