#include <string>
#include <vector>
#include <iostream>
using namespace std;

int a[1010][1010];
int n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    n = board.size(); m = board[0].size();

    for(auto x : skill)
    {
        int attack = x[0] == 1 ? -1 : 1;
        int r1 = x[1], c1 = x[2];
        int r2 = x[3], c2 = x[4];
        int degree = x[5];

        a[r1][c1] += degree * attack;
        a[r1][c2+1] += degree * attack * -1;
        a[r2+1][c1] += degree * attack * -1;
        a[r2+1][c2+1] += degree * attack;
    }

    // 행방향
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            a[i][j] += a[i][j-1];
        }
    }

    // 열방향
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            a[j][i] += a[j-1][i];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            a[i][j] += board[i][j];
            if(a[i][j] > 0) answer++;
        }
    }
    
    return answer;
}
