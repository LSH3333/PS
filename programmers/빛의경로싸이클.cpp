#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int h,w;

void Move(int &r, int &c, int dir)
{
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if(nr >= 0 && nr < h && nc >= 0 && nc < w)
    {
        r = nr;
        c = nc;
        return;
    }

    switch(dir)
    {
        // up
        case 0:
            nr = h-1;
            break;
            // right
        case 1:
            nc = 0;
            break;
            // down
        case 2:
            nr = 0;
            break;
            // left
        case 3:
            nc = w - 1;
            break;
    }

    r = nr; c = nc;
}


vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    h = grid.size();
    w = grid.front().size();
    bool mark[510][510][4];

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {

            for(int tc = 0; tc < 4; tc++)
            {
                int r = i, c = j, cnt = 0;
                if(!mark[r][c][tc]) { cnt++; mark[r][c][tc] = true; }
                else continue;
                int dir = tc;

                while(true)
                {
                    Move(r, c, dir);

                    switch(grid[r][c])
                    {
                        case 'L':
                            dir -= 1;
                            if(dir == -1) dir = 3;
                            break;

                        case 'R':
                            dir += 1;
                            if(dir == 4) dir = 0;
                            break;

                        case 'S':
                            dir = dir;
                            break;
                    }

                    if(mark[r][c][dir]) break;
                    cnt++;
                    mark[r][c][dir] = true;
                }
                if(cnt != 0) answer.push_back(cnt);
            }
        }
    }



    sort(answer.begin(), answer.end());
    return answer;
}