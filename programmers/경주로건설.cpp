#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<vector<int>> _board;
bool mark[26][26][4];


void bfs()
{
    queue<pair<pair<int,int>, tuple<int,int,int>>> q;
    // {r,c}, {dir, depth, bent}
    q.push({{0,0}, make_tuple(-1,0,0)});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dir = get<0>(q.front().second);
        int depth = get<1>(q.front().second);
        int bent = get<2>(q.front().second);
        q.pop();

        if(r == _board.size()-1 && c == _board.size()-1)
        {
            cout << r << ' ' << c << ' ' << dir << ' ' << depth << ' ' << bent << endl;
        }

        for(int i = 0; i < 4; i++)
        {
            if(dir != -1 && abs(dir-i) == 2) continue; // 반대로 방향으로 가지 않는다
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= _board.size() || nc < 0 || nc >= _board.size()) continue;
            // 다음 지점이 벽 or 해당 방향으로 다음 지점 이동한적 있다면 continue
            if(_board[nr][nc] == 1 || mark[nr][nc][dir]) continue;
            int nbent = (dir == i || dir == -1) ? bent : bent+1;
            mark[nr][nc][dir] = true;
            q.push({{nr,nc}, make_tuple(i, depth+1, nbent)});
        }
    }

}

int solution(vector<vector<int>> board) {
    int answer = 0;
    _board = board;

    bfs();

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
    solution(board1);
}