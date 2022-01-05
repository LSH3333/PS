#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 2000000000
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
//vector<vector<int>> mark(30, vector<int>(30, 0));
bool mark[30][30][4];
vector<vector<int>> _board;
int ans = INF;

void bfs()
{
    // {r,c}, {dir,cost}
    queue<pair<pair<int,int>, pair<int,int>>> q;
    mark[0][0][0] = true;
    mark[0][0][1] = true;
    mark[0][0][2] = true;
    mark[0][0][3] = true;
    q.push({{0,0},{-1,0}});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(r == _board.size()-1 && c == _board.size()-1)
        {
            ans = min(ans, cost);
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= _board.size() || nc < 0 || nc >= _board.size()) continue;
            if(_board[nr][nc] == 1) continue;
            int nCost = 0;
            if(dir == -1 || i == dir) nCost = cost + 100;
            else nCost = cost + 600; // 코너는 100원에 500원이 추가로 듦

            if(!mark[nr][nc][i] || nCost <= _board[nr][nc])
            {
                q.push({{nr,nc}, {i,nCost}});
                mark[nr][nc][i] = true;
                _board[nr][nc] = nCost;
            }
        }

    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    _board = board;

    bfs();

    answer = ans;
    return answer;
}

int main()
{
    vector<vector<int>> board2 =
            {
                    {0,0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,1,0,0},
                    {0,0,0,0,1,0,0,0},
                    {0,0,0,1,0,0,0,1},
                    {0,0,1,0,0,0,1,0},
                    {0,1,0,0,0,1,0,0},
                    {1,0,0,0,0,0,0,0}
            };
    vector<vector<int>> board1 =
            {
                    {0,0,0},
                    {0,0,0},
                    {0,0,0}
            };
    vector<vector<int>> board3 =
            {
                    {0,0,1,0},
                    {0,0,0,0},
                    {0,1,0,1},
                    {1,0,0,0}
            };
    solution(board2);
}