#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
////// dp로? 다시풀어야함 
int MOD = 20170805;
int dr[] = {0, 1};
int dc[] = {1, 0};
int M, N;
int cnt = 0;
int mark[510][510];
vector<vector<int>> map;
bool possible;

void dfs(int r, int c, int dir)
{
    if(r == M-1 && c == N-1)
    {
        possible = true;
        return;
    }
    if(map[r][c] == 1)
    {
        possible = false;
        return;
    }


    for(int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
        // 다음 도로가 2이면 직진만 가능
        if(map[r][c] == 2 && dir != -1 && dir != i) continue;

        mark[nr][nc] = true;
        dfs(nr, nc, i);
        if(!possible) mark[nr][nc] = false;
    }

}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m; N = n;
    map = city_map;
    cnt = 0;

    dfs(0,0,-1);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mark[i][j] << ' ';
        } cout << endl;
    }cout <<endl;

    cout << cnt;
    answer = cnt;
    return answer;
}

int main()
{
    vector<vector<int>> city_map1 =
            {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}
            };
    vector<vector<int>> city_map2 =
            {
                    {0, 2, 0, 0, 0, 2},
                    {0, 0, 2, 0, 1, 0},
                    {1, 0, 0, 2, 2, 0}
            };
    vector<vector<int>> tmp1 =
            {
                    {0,0,0},
                    {0,0,1},
                    {0,0,0}
            };

    solution(3,3, tmp1);
}