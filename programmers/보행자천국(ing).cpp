#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int MOD = 20170805;
int M, N;
vector<vector<int>> map;

void Print(vector<vector<vector<int>>> &mark)
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                cout << mark[i][j][k] << ' ';
            } cout<<endl;
        }cout << endl;
    }
}

bool dfs(int r, int c, int dir, vector<vector<vector<int>>> &mark)
{
    if(r < 0 || r >= M || c < 0 || c >= N) return false;
    if(dir!=-1 && mark[dir][r][c] != -1) return true;
    if(r == M-1 && c == N-1) return true;
    if(dir != -1 && (mark[1][r][c] > 0 || mark[0][r][c] > 0)) return true;

    int dr[] = {0, 1};
    int dc[] = {1, 0};
    cout << r << ' ' << c << ' ' << endl;
    bool IsPossible = false;
    for(int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(map[r][c] == 2 && dir != -1 && dir != i) continue;
        if(map[nr][nc] == 1) continue;

        cout << "in: " << nr << ' ' << nc << endl;
        if(dfs(nr, nc, i, mark))
        {
            IsPossible = true;
            if(nr == M-1 && nc == N-1)
            {
                mark[i][r][c] = 1;
            }
            else if(map[nr][nc] == 0)
            {
                mark[i][r][c] = (mark[i][r][c] + mark[0][nr][nc] + mark[1][nr][nc]) % MOD;
            }
            else if(map[nr][nc] == 2)
            {
                mark[i][r][c] = (mark[i][r][c] + mark[i][nr][nc]) % MOD;
            }
        }
    }
    return IsPossible;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m; N = n;
    map = city_map;
    MOD = 20170805;
    vector<vector<vector<int>>> mark(2, vector<vector<int>>(M+1, vector<int>(N+1,-1)));

    if(n == 1 && m == 1) return 1;

    dfs(0, 0, -1, mark);
    Print(mark);
    mark[0][0][0] = mark[0][0][0] < 0 ? 0 : mark[0][0][0];
    mark[1][0][0] = mark[1][0][0] < 0 ? 0 : mark[1][0][0];
    answer = (mark[0][0][0] + mark[1][0][0]) % MOD;
    cout << answer;
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
    vector<vector<int>> tmp2 =
            {
                    {0,1},
                    {0,0}
            };
    vector<vector<int>> tmp3(2, vector<int>(400,0));
    solution(3, 3, city_map1);

}