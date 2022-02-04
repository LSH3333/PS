#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<int> per;
int _r, _c;
int answer = 99999;

void bfs(vector<vector<int>> board)
{
    int curR = _r;
    int curC = _c;
    int cnt = 0;
    for(int idx = 0; idx < per.size(); idx++)
    {
        for(int twice = 0; twice < 2; twice++)
        {
            int target = per[idx];
            queue<pair<pair<int,int>,int>> q;
            bool mark[4][4] = {false, };

            q.push({{curR, curC}, 0});
            mark[curR][curC] = true;

            while(!q.empty())
            {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int depth = q.front().second;
                q.pop();
//                cout << "target: " << target << endl;
//                cout << r << ' ' << c << ' ' << depth << endl;
                if(board[r][c] == target)
                {
//                    cout << "-----------found, depth: " << depth << endl;
                    cnt += depth+1;
                    curR = r; curC = c;
                    board[r][c] = 0;
                    break;
                }

                // 한칸씩 이동
                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
                    if(mark[nr][nc]) continue;
                    mark[nr][nc] = true;
                    q.push({{nr,nc}, depth+1});
                }

                // 컨트롤 키를 이용한 이동
                for(int i = 0; i < 4; i++)
                {
                    int nr = r, nc = c;
                    while(true)
                    {
                        nr = nr + dr[i];
                        nc = nc + dc[i];

                        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
                        {
                            nr = nr - dr[i];
                            nc = nc - dc[i];
                            break;
                        }
                        if(board[nr][nc] != 0) break;
                    }
                    if(!mark[nr][nc])
                    {
                        mark[nr][nc] = true;
                        q.push({{nr,nc}, depth+1});
                    }
                }
            }
        }
//        cout << "cnt: " << cnt << endl;
    }
    answer = min(answer, cnt);
}

int solution(vector<vector<int>> board, int r, int c)
{
    _r = r; _c = c;
    for(auto x : board)
    {
        for(auto y : x)
        {
            if(y != 0) per.push_back(y);
        }
    }
    sort(per.begin(), per.end());
    per.erase(unique(per.begin(), per.end()), per.end());

    do {
//        cout << "per: ";
//        for(auto x : per) cout << x << ' '; cout << endl;
        bfs(board);
    } while(next_permutation(per.begin(), per.end()));

//    cout << answer;
    return answer;
}

int main()
{
//    vector<vector<int>> board =
//            {
//                    {1,0,0,3},
//                    {2,0,0,0},
//                    {0,0,0,2},
//                    {3,0,1,0}
//            };
//    solution(board, 1, 0);

    vector<vector<int>> board =
            {
                    {3,0,0,2},
                    {0,0,1,0},
                    {0,1,0,0},
                    {2,0,0,3}
            };
    solution(board, 0, 1);
}