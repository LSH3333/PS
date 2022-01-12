#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    int MOD = 20170805;
    int mark[2][501][501];
    int map[501][501] = {0,};
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            map[i][j] = city_map[i-1][j-1];
        }
    }
    fill(&mark[0][0][0], &mark[1][500][500], 0);

    map[1][1] = 2;
    mark[0][1][1] = 1;
    mark[1][1][1] = 1;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == 1 && j == 1) continue;
            if(map[i][j] == 1) continue;

            // 왼쪽이 일방통행일 경우
            if(map[i][j-1] == 2)
            {
                mark[0][i][j] = mark[0][i][j-1] % MOD;
            }
            else
            {
                mark[0][i][j] = (mark[0][i][j-1] + mark[1][i][j-1]) % MOD;
            }
            // 위가 일방통행일 경우
            if(map[i-1][j] == 2)
            {
                mark[1][i][j] = mark[1][i-1][j] % MOD;
            }
            else
            {
                mark[1][i][j] = (mark[0][i-1][j] + mark[1][i-1][j]) % MOD;
            }
        }
    }
    
    answer = (mark[0][m][n] + mark[1][m][n]) % MOD;
    return answer;
}