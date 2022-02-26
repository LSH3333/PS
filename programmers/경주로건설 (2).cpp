#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
bool mark[30][30][4];
int _board[30][30];
int answer = 999999999;

void bfs(vector<vector<int>> &board)
{
    // {r,c}, {dir, money}
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push({{0,0}, {-1,0}});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = q.front().second.first;
        int money = q.front().second.second;
        q.pop();

        // 도착 지점
        if(r == N-1 && c == N-1)
        {
//            cout << money << endl;
            answer = min(answer, money);
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(board[nr][nc] == 1) continue; // 벽

            int sum = money;
            if(dir == i || dir == -1) sum += 100; // 직선
            else sum += 600; // 코너

            // 해당 지점 해당 방향으로 아직 방문 안함 or
            // 방문 했지만 더 낮은 가격으로 이동 가능
            if(!mark[nr][nc][i] || _board[nr][nc] >= sum)
            {
                mark[nr][nc][i] = true;
                _board[nr][nc] = sum;
                q.push({{nr, nc}, {i, sum}});
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
    vector<vector<int>> board =
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
    solution(board);
}