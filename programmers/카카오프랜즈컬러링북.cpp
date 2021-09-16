#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dr[4];
int dc[4];

bool mark[110][110];
int cnt = 0;

void dfs(int r, int c, int m, int n, vector<vector<int>> picture)
{
    if(mark[r][c]) return;
    mark[r][c] = true;
    cnt++;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if(picture[nr][nc] != picture[r][c]) continue;
        dfs(nr,nc,m,n,picture);
    }
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    cnt = 0;
    dr[0]=-1; dr[1]=0; dr[2]=1; dr[3]=0;
    dc[0]=0; dc[1]=1; dc[2]=0; dc[3]=-1;
    fill(&mark[0][0], &mark[109][109], false);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!mark[i][j] && picture[i][j] != 0)
            {
                dfs(i,j,m,n,picture);
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, cnt);
                cnt = 0;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    return answer;
}