#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

bool mark[110][110][4];
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 2000000000;

struct node
{
    int r1;
    int c1;
    int dir1;

    int r2;
    int c2;
    int dir2;

    int depth;
};

void bfs(vector<vector<int>> &board)
{
    queue<node> q;
    mark[0][0][1] = true;
    mark[0][1][3] = true;
    q.push({0, 0, 1, 0, 1, 3, 0});

    while(!q.empty())
    {
        int r1 = q.front().r1;
        int c1 = q.front().c1;
        int dir1 = q.front().dir1;
        int r2 = q.front().r2;
        int c2 = q.front().c2;
        int dir2 = q.front().dir2;
        int depth = q.front().depth;
        q.pop();
//        cout << "depth: " << depth << endl;
//        cout << "(" << r1 << "," << c1 << "," << dir1 << ")" << ' ';
//        cout << "(" << r2 << "," << c2 << "," << dir2 << ")" << endl;

        if((r1==N-1 && c1==N-1) || (r2==N-1 && c2==N-1))
        {
            answer = min(answer, depth);
        }

        for(int i = 0; i < 4; i++)
        {
            int nr1 = r1 + dr[i];
            int nc1 = c1 + dc[i];
            int nr2 = r2 + dr[i];
            int nc2 = c2 + dc[i];
            if(nr1 < 0 || nr1 >= N || nc1 < 0 || nc1 >= N ||
               nr2 < 0 || nr2 >= N || nc2 < 0 || nc2 >= N) continue;
            if(mark[nr1][nc1][dir1] || mark[nr2][nc2][dir2]) continue;
            if(board[nr1][nc1] == 1 || board[nr2][nc2] == 1) continue;
            mark[nr1][nc1][dir1] = true;
            mark[nr2][nc2][dir2] = true;
            q.push({nr1, nc1, dir1, nr2, nc2, dir2, depth+1});
        }

        // 좌우 방향인 경우
        if(dir1 == 1 || dir1 == 3)
        {
            int left_r, left_c, right_r, right_c;
            if(c1 < c2) {left_r = r1; left_c = c1; right_r = r2; right_c = c2;}
            else {left_r = r2; left_c = c2; right_r = r1; right_c = c1;}
            // 왼쪽 기준 시계방향 회전
            if(left_r+1 < N && board[left_r+1][left_c] == 0 && board[left_r+1][left_c+1] == 0
               && !mark[left_r][left_c][2] && !mark[right_r+1][right_c-1][0])
            {
                q.push({left_r, left_c, 2, right_r+1, right_c-1, 0, depth+1});
                mark[left_r][left_c][2] = true;
                mark[right_r+1][right_c-1][0] = true;
            }

            // 왼쪽 기준 반시계방향 회전
            if(left_r-1 >= 0 && board[left_r-1][c1] == 0 && board[left_r-1][left_c+1] == 0
               && !mark[left_r][left_c][0] && !mark[right_r-1][right_c-1][2])
            {
                q.push({left_r, left_c, 0, right_r-1, right_c-1, 2, depth+1});
                mark[left_r][left_c][0] = true;
                mark[right_r-1][right_c-1][2] = true;
            }

            // 오른쪽 기준 시계방향 회전
            if(right_r-1 >= 0 && board[right_r-1][right_c] == 0 && board[right_r-1][right_c-1] == 0
               && !mark[right_r][right_c][0] && !mark[left_r-1][left_c+1][2])
            {
                q.push({left_r-1, left_c+1, 2, right_r, right_c, 0, depth+1});
                mark[left_r-1][left_c+1][2] = true;
                mark[right_r][right_c][0] = true;
            }

            // 오른쪽 기준 반시계방향 회전
            if(right_r+1 < N && board[right_r+1][right_c] == 0 && board[right_r+1][right_c-1] == 0
               && !mark[right_r][right_c][2] && !mark[left_r+1][left_c+1][0])
            {
                q.push({left_r+1, left_c+1, 0, right_r, right_c, 2, depth+1});
                mark[left_r+1][left_c+1][0] = true;
                mark[right_r][right_c][2] = true;
            }

        }
            // 상하 방향인 경우
        else
        {
            int up_r, up_c, down_r, down_c;
            if(r1 < r2) {up_r = r1; up_c = c1; down_r = r2; down_c = c2;}
            else {up_r = r2; up_c = c2; down_r = r1; down_c = c1;}

            // 위 기준 시계 방향 회전
            if(up_c-1 >= 0 && board[up_r][up_c-1] == 0 && board[up_r+1][up_c-1] == 0
               && !mark[up_r][up_c][3] && !mark[down_r-1][down_c-1][1])
            {
                q.push({up_r, up_c, 3, down_r-1, down_c-1, 1, depth+1});
                mark[up_r][up_c][3] = true;
                mark[down_r-1][down_c-1][1] = true;
            }

            // 위 기준 반시계 방향 회전
            if(up_c+1 < N && board[up_r][up_c+1] == 0 && board[up_r+1][up_c+1] == 0
               && !mark[up_r][up_c][1] && !mark[down_r-1][down_c+1][3])
            {
                q.push({up_r, up_c, 1, down_r-1, down_c+1, 3, depth+1});
                mark[up_r][up_c][1] = true;
                mark[down_r-1][down_c+1][3] = true;
            }

            // 아래 기준 시계 방향 회전
            if(down_c+1 < N && board[down_r][down_c+1] == 0 && board[down_r-1][down_c+1] == 0
               && !mark[down_r][down_c][1] && !mark[up_r+1][up_c+1][3])
            {
                q.push({up_r+1, up_c+1, 3, down_r, down_c, 1, depth+1});
                mark[up_r+1][up_c+1][3] = true;
                mark[down_r][down_c][1] = true;
            }

            // 아래 기준 반시계 방향 회전
            if(down_c-1 >= 0 && board[down_r][down_c-1] == 0 && board[down_r-1][down_c-1] == 0
               && !mark[down_r][down_c][3] && !mark[up_r+1][up_c-1][1])
            {
                q.push({up_r+1, up_c-1, 1, down_r, down_c, 3, depth+1});
                mark[up_r+1][up_c-1][1] = true;
                mark[down_r][down_c][3] = true;
            }

        }
    }
}
int solution(vector<vector<int>> board)
{
    N = board.size();

    bfs(board);

//    cout << answer;
    return answer;
}

int main()
{
//    vector<vector<int>> board =
//            {
//                    {0,0,0,1,1},
//                    {0,0,0,1,0},
//                    {0,1,0,1,1},
//                    {1,1,0,0,1},
//                    {0,0,0,0,0}
//            };
//    solution(board);

//    vector<vector<int>> board =
//            {
//                    {0, 0, 0, 0, 1, 0},
//                    {0, 0, 1, 1, 1, 0},
//                    {0, 1, 1, 1, 1, 0},
//                    {0, 1, 0, 0, 1, 0},
//                    {0, 0, 1, 0, 0, 0},
//                    {0, 0, 0, 0, 0, 0}
//            };
//    solution(board);
    vector<vector<int>> board =
            {
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}
            };
    solution(board);
}