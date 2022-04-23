#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &board, vector<vector<bool>> &used, int target, int &R, int &C)
{
    vector<vector<bool>> mark(4, vector<bool>(4, false));
    queue<pair<pair<int,int>, int>> q;

    mark[R][C] = true;
    q.push({{R,C}, 0});
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // Check
        // 내가 찾는 카드 && 아직 뒤집지 않은 카드
        if(board[r][c] == target && !used[r][c])
        {
            used[r][c] = true;
            board[r][c] = 0; // 카드 뒤집기
            R = r; C = c;
            return cnt;
        }

        // 4방향 컨트롤 이동
        for(int i = 0; i < 4; i++)
        {
            int nr = r, nc = c;
            while(true)
            {
                nr = nr + dr[i];
                nc = nc + dc[i];
                if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) // 해당 방향 끝 도달
                {
                    if(nr-dr[i] != r || nc-dc[i] != c)
                    {
                        if(!mark[nr-dr[i]][nc-dc[i]])
                        {
                            nr = nr - dr[i]; nc = nc - dc[i];
                            mark[nr][nc] = true;
                            q.push({{nr,nc}, cnt+1});
                        }
                    }
                    break;
                }
                // 카드 찾음
                if(board[nr][nc] != 0 && mark[nr][nc] == false)
                {q.push({{nr,nc}, cnt+1}); mark[nr][nc] = true; break; }
            }
        }

        // 한 칸 이동
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
            if(mark[nr][nc]) continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, cnt+1});
        }
    }
    return -1;
}

int Cal(vector<vector<int>> &board, const vector<int> &order, int R, int C)
{
    vector<vector<bool>> used(4, vector<bool>(4, false));
    int cnt = 0;

    for(auto target : order)
    {
        // 한짝은 두장
        for(int i = 0; i < 2; i++)
        {
            // 이동 횟수 + 엔터키
            int cur = bfs(board, used, target, R, C);
            cnt += cur + 1;
        }
    }

    return cnt;
}

int solution(vector<vector<int>> board, int r, int c)
{
    // 순서 조합
    vector<int> orders;
    int maxN = 0;
    for(auto x : board) maxN = max(maxN, *max_element(x.begin(), x.end()));
    for(int i = 1; i <= maxN; i++) orders.push_back(i);




    int answer = 99999;
    do
    {
        // board 복사
        vector<vector<int>> _board = board;
        answer = min(answer, Cal(_board, orders, r, c));
//        cout << answer << endl;
    } while(next_permutation(orders.begin(), orders.end()));

//    cout << answer;
    return answer;
}



int main()
{
//    vector<vector<int>> board =
//            {
//                    {3,0,0,2},
//                    {0,0,1,0},
//                    {0,1,0,0},
//                    {2,0,0,3}
//            };

    vector<vector<int>> board =
            {
                    {1,0,0,3},
                    {2,0,0,0},
                    {0,0,0,2},
                    {3,0,1,0}
            };
    solution(board, 1, 0);
}





//////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>> &board, pair<int,pair<int,int>> target, int &R, int &C)
{
    vector<vector<bool>> mark(4, vector<bool>(4, false));
    queue<pair<pair<int,int>, int>> q;

    mark[R][C] = true;
    q.push({{R,C}, 0});
    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // Check
        // 내가 찾는 카드 && 아직 뒤집지 않은 카드
        if(r == target.second.first && c == target.second.second)
        {
            board[r][c] = 0; // 카드 뒤집기
            R = r; C = c;
            return cnt;
        }

        // 4방향 컨트롤 이동
        for(int i = 0; i < 4; i++)
        {
            int nr = r, nc = c;
            while(true)
            {
                nr = nr + dr[i];
                nc = nc + dc[i];
                if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) // 해당 방향 끝 도달
                {
                    if(nr-dr[i] != r || nc-dc[i] != c)
                    {
                        if(!mark[nr-dr[i]][nc-dc[i]])
                        {
                            nr = nr - dr[i]; nc = nc - dc[i];
                            mark[nr][nc] = true;
                            q.push({{nr,nc}, cnt+1});
                        }
                    }
                    break;
                }
                // 카드 찾음
                if(board[nr][nc] != 0 && !mark[nr][nc])
                {q.push({{nr,nc}, cnt+1}); mark[nr][nc] = true; break; }
            }
        }

        // 한 칸 이동
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
            if(mark[nr][nc]) continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, cnt+1});
        }
    }
    return -1;
}

int Cal(vector<vector<int>> &board, const vector<pair<int,pair<int,int>>> &order, int R, int C)
{
    int cnt = 0;

    cout << "order: ";
    for(auto x : order) cout << x.first << ' ';  cout << endl;
    for(auto target : order)
    {
        int cur = bfs(board, target, R, C);
        cnt += cur + 1;
    }

    cout << cnt << endl << endl;
    return cnt;
}

int solution(vector<vector<int>> board, int r, int c)
{
    // 순서 조합
    vector<int> orders;
    int maxN = 0;
    for(auto x : board) maxN = max(maxN, *max_element(x.begin(), x.end()));
    for(int i = 1; i <= maxN; i++) orders.push_back(i);


    vector<pair<int,pair<int,int>>> ord;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == 0) continue;
            ord.push_back({board[i][j], {i, j}});
        }
    }

    sort(ord.begin(), ord.end());

    int answer = 99999;
    do
    {
        // board 복사
        vector<vector<int>> _board = board;
        answer = min(answer, Cal(_board, ord, r, c));
    } while(next_permutation(ord.begin(), ord.end()));

    cout << answer;
    return answer;
}



int main()
{
//    vector<vector<int>> board =
//            {
//                    {3,0,0,2},
//                    {0,0,1,0},
//                    {0,1,0,0},
//                    {2,0,0,3}
//            };

    vector<vector<int>> board =
            {
                    {1,0,0,3},
                    {2,0,0,0},
                    {0,0,0,2},
                    {3,0,1,0}
            };
    solution(board, 1, 0);
}
