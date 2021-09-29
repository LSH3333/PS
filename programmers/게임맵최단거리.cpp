#include<vector>
#include <iostream>
#include <queue>
using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int mark[110][110];
int n,m;

void bfs(int r, int c, vector<vector<int>> &map)
{
    queue<pair<int,int>> q;
    q.push({r,c});
    mark[r][c] = 1;

    while(!q.empty())
    {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr >= n || nnc < 0 || nnc >= m) continue;
            if(map[nnr][nnc] == 0 || mark[nnr][nnc] != 0) continue;
            q.push({nnr,nnc});
            mark[nnr][nnc] = mark[nr][nc]+1;
        }
    }

}


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();

    bfs(0,0,maps);
    cout << endl;

    mark[n-1][m-1] == 0 ? answer = -1 : answer = mark[n-1][m-1];

    return answer;
}