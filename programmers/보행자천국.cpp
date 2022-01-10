#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int MOD = 20170805;
int M, N;
int mark[2][501][501];

int dfs(int r, int c, int dir, vector<vector<int>> &map)
{
    // 도착지점 도달 
    if(r == M-1 && c == N-1) return 1;
    // 해당 방향으로 진행한 기록이 있음 
    if(mark[dir][r][c] != -1)
    {
        // 현재 칸이 0이라면 아래, 오른쪽 방향의 합 리턴 
        if(map[r][c] == 0)
        {
            int a = mark[0][r][c] == -1 ? 0 : mark[0][r][c];
            int b = mark[1][r][c] == -1 ? 0 : mark[1][r][c];
            return (a + b) % MOD;
        }
        // 현재 칸이 2라면, 진행 방향 값만 리턴 
        else if(map[r][c] == 2)
        {
            return mark[dir][r][c] % MOD;
        }
    }

    int dr[] = {0, 1};
    int dc[] = {1, 0};

    for(int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 현재 칸이 2라면, 직진만 가능 
        if(map[r][c] == 2 && dir != -1 && dir != i) continue;
        // 다음칸이 범위 벗어났다면 or 벽이라면, 해당 방향 0 기록하고 진행하지 않음 (가도 벽이라 막힘) 
        if((nr < 0 || nr >= M || nc < 0 || nc >= N) || map[nr][nc]==1) { mark[i][r][c] = 0; continue; }

        mark[i][r][c] = dfs(nr, nc, i, map);
    }

    if(map[r][c] == 0)
    {
        int a = mark[0][r][c] == -1 ? 0 : mark[0][r][c];
        int b = mark[1][r][c] == -1 ? 0 : mark[1][r][c];
        return (a + b) % MOD;
    }
    else if(map[r][c] == 2)
    {
        return mark[dir][r][c] % MOD;
    }
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m; N = n;
    MOD = 20170805;
    memset(mark, -1, sizeof(mark));

    dfs(0, 0, 0, city_map);

    answer = (mark[0][0][0] + mark[1][0][0]) % MOD;

    return answer;
}


