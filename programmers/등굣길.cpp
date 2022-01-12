#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007
using namespace std;

int mark[110][110];
int map[110][110];
int dr[] = {0, 1};
int dc[] = {1, 0};
// 가로, 세로
int M, N;
void dfs(int r, int c)
{
    for(int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 다음 지점이 벽이거나 웅덩이
        if((nr <= 0 || nr > N || nc <= 0 || nc > M) || map[nr][nc] == 1)
        {
            continue;
        }
        // 다음 지점이 도착지점
        if(nr == N && nc == M)
        {
            mark[r][c] = 1;
            continue;
        }
        if(mark[nr][nc] != 0)
        {
            mark[r][c] += (mark[nr][nc] % MOD);
            continue;
        }

        dfs(nr, nc);

        mark[r][c] += (mark[nr][nc] % MOD);
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    M = m; N = n;
    
    for(auto x : puddles) map[x[1]][x[0]] = 1;
    
    dfs(1,1);

    answer = (mark[1][1] % MOD);
    return answer;
}
