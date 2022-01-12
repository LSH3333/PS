#include <string>
#include <vector>
#include <iostream>
#define MOD 1000000007
using namespace std;

int map[110][110];
int mark[110][110];
// 가로, 세로
int M, N;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    M = m; N = n;
    for(auto x : puddles) map[x[1]][x[0]] = -1;

    mark[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i == 1 && j == 1) continue;
            if(map[i][j] == -1) continue;
            mark[i][j] = (mark[i][j-1] + mark[i-1][j]) % MOD;
        }
    }
    
    answer = mark[n][m] % MOD;
    return answer;
}