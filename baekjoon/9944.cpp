#include <iostream>
#include <vector>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int N, M;
int answer = 10000000;

// dir 방향으로 끝까지 이동, 방문한 칸 -로 방문 처리
// 방문한 칸 수 리턴, r,c는 최종 칸 값 갖음
int MoveOneWay(vector<vector<char>> &board, int &r, int &c, int dir, vector<pair<int,int>> &visitedPos)
{
    int cnt = 0;
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    while((nr >= 0 && nr < N && nc >= 0 && nc < M) && board[nr][nc] == '.')
    {
        visitedPos.push_back({nr,nc});
        board[nr][nc] = '-'; // 방문 처리
        cnt++;
        nr = nr + dr[dir];
        nc = nc + dc[dir];
    }

    r = nr - dr[dir];
    c = nc - dc[dir];
    return cnt;
}

// 방문한곳 미방문 처리해서 복구
void Restore(vector<vector<char>> &board, vector<pair<int,int>> &visitedPos)
{
    for(auto x : visitedPos)
    {
        board[x.first][x.second] = '.';
    }
}

void dfs(vector<vector<char>> &board, int r, int c, int depth, int visitedCnt, int emptyCnt)
{
    if(visitedCnt == emptyCnt)
    {
        answer = min(answer, depth);
        return;
    }

    for(int dir = 0; dir < 4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(board[nr][nc] != '.') continue;

        int _r = r, _c = c;
        vector<pair<int,int>> visitedPos;
        int curVisited = MoveOneWay(board, r, c, dir, visitedPos);
        visitedCnt += curVisited;

        dfs(board, r, c, depth+1, visitedCnt, emptyCnt);

        Restore(board, visitedPos);
        visitedCnt -= curVisited;
        r = _r; c = _c;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T = 1;
    while(cin >> N >> M)
    {
        answer = 10000000;
        int emptyCnt = 0; // 방문해야할 칸 수
        // . : 빈칸, * : 장애물, - : 방문
        vector<vector<char>> board(N, vector<char>(M));
        for(int i = 0; i < N; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < M; j++)
            {
                board[i][j] = s[j];
                if(board[i][j] == '.') emptyCnt++;
            }
        }

        for(int r = 0; r < N; r++)
        {
            for(int c = 0; c < M; c++)
            {
                if(board[r][c] != '.') continue;
                vector<vector<char>> _board = board;
                _board[r][c] = '-';
                dfs(_board, r, c, 0, 1, emptyCnt);
            }
        }

        if(answer == 10000000) answer = -1;
        cout << "Case " << T << ": " << answer << '\n';

        T++;
    }


}