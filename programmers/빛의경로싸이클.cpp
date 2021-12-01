------------ 미완성, 저장용 -----------------
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int h,w;

vector<string> v;
int cnt = 0;

vector<int> Move(int r, int c, int dir)
{
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if(nr >= 0 && nr < h && nc >= 0 && nc < w)
    {
        vector<int> ret = {nr, nc};
        return vector<int>{nr,nc};
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

    return vector<int>{nr, nc};
}

void dfs(int r, int c, int dir, vector<string> &grid)
{
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


    vector<int> next = Move(r, c, dir);

    string before = to_string(r) + to_string(c);
    string after = to_string(next[0]) + to_string(next[1]);
    string direction = to_string(dir);

    auto it = find(v.begin(), v.end(), before + after + direction);
    if(it != v.end()) return;
    cnt++;
    v.push_back(before+after+direction);


    dfs(next[0], next[1], dir, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    h = grid.size();
    w = grid[0].size();

    for(int dir = 0; dir < 4; dir++)
    {
        cnt = 0;
        dfs(0, 0, dir, grid);
        if(cnt != 0) answer.push_back(cnt);
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<string> grid = {"R", "R"};
    solution(grid);
}