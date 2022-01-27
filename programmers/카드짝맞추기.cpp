#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int R, C;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};


int bfs(vector<int> &v, vector<vector<int>> &original)
{
    vector<vector<int>> _board = original;
    int cnt = 0;
    int cursorR = R, cursorC = C; // 커서는 최초 위치

    for(int i = 0; i < v.size(); i++)
    {
        int foundR = -1, foundC = -1; // 찾은 한짝의 위치 기억
        int target = v[i];
        // 한짝 찾고, 나머지 한짝 찾음. 총 두번
        for(int twice = 0; twice < 2; twice++)
        {
            bool mark[4][4] = {false,};
            queue<pair<pair<int,int>, int>> q;
            mark[cursorR][cursorC] = true;
            q.push({{cursorR, cursorC},0});

            while(!q.empty())
            {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int depth = q.front().second;
                q.pop();

                // target 찾음 && 이미 찾은짝 아님
                if(_board[r][c] == target)
                {
                    cnt += depth+1; // 찾은 한짝에서 엔터키 쳐야하므로 +1
                    cursorR = r; cursorC = c; // 찾은 위치로 커서이동
                    foundR = r; foundC = c;
                    break;
                }

                // 한칸씩 이동
                for(int j = 0; j < 4; j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
                    if(mark[nr][nc]) continue;
                    mark[nr][nc] = true;
                    q.push({{nr,nc}, depth+1});
                }

                // 컨트롤키를 이용한 이동
                // 4방향으로 보드의 끝 or 카드를 만날때까지 이동
                for(int j = 0; j < 4; j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    while(true)
                    {
                        // 보드의 끝 도달
                        if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4)
                        {
                            nr -= dr[j];
                            nc -= dc[j];
                            break;
                        }
                        if(_board[nr][nc] != 0) break;
                        nr += dr[j];
                        nc += dc[j];
                    }
                    if(!mark[nr][nc])
                    {
                        mark[nr][nc] = true;
                        q.push({{nr,nc}, depth+1});
                    }
                }

            }
            // 찾은짝 지움
            _board[foundR][foundC] = 0;
        }
    }
    return cnt;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 200000;
    R = r; C = c;
    // board 배열에서의 최댓값
    int maxVal = 0;
    for(auto x : board)
        maxVal = max(maxVal, *max_element(x.begin(), x.end()));

    vector<int> v;
    for(int i = 1; i <= maxVal; i++) v.push_back(i);
    // 프렌즈를 어떤 순서로 맞출것인가를 순열로 구함
    do {
        answer = min(answer, bfs(v, board));
    } while(next_permutation(v.begin(),v.end()));

    return answer;
}
