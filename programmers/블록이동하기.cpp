#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

bool mark[110][110][4];
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct node
{
    int r;
    int c;
    int dir;
    int depth;
};

vector<int> FindNextBlock(int r, int c, int dir)
{
    vector<int> v(3,0);
    v[2] = (dir + 2) % 4;
    if(dir == 0) { v[0] = r-1; v[1] = c;}
    else if(dir == 1) {v[0] = r; v[1] = c+1;}
    else if(dir == 2) {v[0] = r+1; v[1] = c;}
    else if(dir == 3) {v[0] = r; v[1] = c-1;}
    return v;
}

int bfs(vector<vector<int>> &board)
{
    queue<node> q;
    mark[0][0][1] = true;
    mark[0][1][3] = true;
    q.push({0, 0, 1, 0});

    while(!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        int dir = q.front().dir;
        int depth = q.front().depth;
        vector<int> nextBlock = FindNextBlock(r, c, dir);
        int r2 = nextBlock[0];
        int c2 = nextBlock[1];
        int dir2 = nextBlock[2];
        q.pop();

        if((r==N-1 && c==N-1) || (r2==N-1 && c2==N-1)) return depth;

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int nr2 = r2 + dr[i];
            int nc2 = c2 + dc[i];

            if(nr < 0 || nr >= N || nc < 0 || nc >= N || nr2 < 0 || nr2 >= N || nc2 < 0 || nc2 >= N) continue;
            if(board[nr][nc] == 1 || board[nr2][nc2] == 1) continue;
            if(mark[nr][nc][dir] || mark[nr2][nc2][dir2]) continue;
            mark[nr][nc][dir] = true;
            mark[nr2][nc2][dir2] = true;
            q.push({nr, nc, dir, depth+1});
        }

        // 회전
        // 좌우
        if(dir == 1 || dir == 3)
        {
            int left_r, left_c, right_r, right_c;
            if(dir == 1) { left_r = r; left_c = c; right_r = r2; right_c = c2; }
            else { left_r = r2; left_c = c2; right_r = r; right_c = c; }

            // 위로 회전
            if(left_r-1 >= 0 && board[left_r-1][left_c] == 0 && board[left_r-1][left_c+1] == 0)
            {
                // left가 회전
                if(!mark[left_r-1][left_c+1][2] && !mark[right_r][right_c][0])
                {
                    q.push({left_r-1, left_c+1, 2, depth+1});
                    mark[left_r-1][left_c+1][2] = true;
                    mark[right_r][right_c][0] = true;
                }
                // right가 회전
                if(!mark[left_r][left_c][0] && !mark[right_r-1][right_c-1][2])
                {
                    q.push({right_r-1, right_c-1, 2, depth+1});
                    mark[left_r][left_c][0] = true;
                    mark[right_r-1][right_c-1][2] = true;
                }
            }
            // 아래로 회전
            if(left_r+1 < N && board[left_r+1][left_c] == 0 && board[left_r+1][left_c+1] == 0)
            {
                // left가 회전
                if(!mark[left_r+1][left_c+1][0] && !mark[right_r][right_c][2])
                {
                    q.push({left_r+1, left_c+1, 0, depth+1});
                    mark[left_r+1][left_c+1][0] = true;
                    mark[right_r][right_c][2] = true;
                }
                // right가 회전
                if(!mark[left_r][left_c][2] && !mark[right_r+1][right_c-1][0])
                {
                    q.push({right_r+1, right_c-1, 0, depth+1});
                    mark[left_r][left_c][2] = true;
                    mark[right_r+1][right_c-1][0] = true;
                }
            }
        }
            // 상하
        else
        {
            int up_r, up_c, down_r, down_c;
            if(dir == 0) { up_r = r2; up_c = c2; down_r = r; down_c = c; }
            else {up_r = up_r = r; up_c = c; down_r = r2; down_c = c2; }

            // 좌로 회전
            if(up_c-1 >= 0 && board[up_r][up_c-1] == 0 && board[up_r+1][up_c-1] == 0)
            {
                // up이 회전
                if(!mark[up_r+1][up_c-1][1] && !mark[down_r][down_c][3])
                {
                    q.push({up_r+1, up_c-1, 1, depth+1});
                    mark[up_r+1][up_c-1][1] = true;
                    mark[down_r][down_c][3] = true;
                }
                // down이 회전
                if(!mark[up_r][up_c][3] && !mark[down_r-1][down_c-1][1])
                {
                    q.push({down_r-1, down_c-1, 1, depth+1});
                    mark[up_r][up_c][3] = true;
                    mark[down_r-1][down_c-1][1] = true;
                }
            }
            // 우로 회전
            if(up_c+1 < N && board[up_r][up_c+1] == 0 && board[up_r+1][up_c+1] == 0)
            {
                // up이 회전
                if(!mark[up_r+1][up_c+1][3] && !mark[down_r][down_c][1])
                {
                    q.push({up_r+1, up_c+1, 3, depth+1});
                    mark[up_r+1][up_c+1][3] = true;
                    mark[down_r][down_c][1] = true;
                }
                // down이 회전
                if(!mark[up_r][up_c][1] && !mark[down_r-1][down_c+1][3])
                {
                    q.push({down_r-1, down_c+1, 3, depth+1});
                    mark[up_r][up_c][1] = true;
                    mark[down_r-1][down_c+1][3] = true;
                }
            }
        }
    }
    return -1;
}
int solution(vector<vector<int>> board)
{
    N = board.size();

    int answer = bfs(board);

//    cout << answer;
    return answer;
}