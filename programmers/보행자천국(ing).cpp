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
    if(map[r][c] == 1)
    {
        return false;
    }
    if(dir != -1 && map[r][c] == 2 && mark[dir][r][c] == -2)
    {
        return false;
    }
    if(mark[0][r][c] > 0 || mark[1][r][c] > 0)
    {
        return true;
    }

    int dr[] = {0, 1};
    int dc[] = {1, 0};
    bool isPossible = false;
    for(int i = 0; i < 2; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        // 다음 도로가 2이면 직진만 가능
        if(map[r][c] == 2 && dir != -1 && dir != i) continue;

        // 다음 칸이 도착지점으로 가는 경로라면
        if(dfs(nr, nc, i, mark))
        {
            isPossible = true;
            if(map[nr][nc] == 0)
            {
                int a = mark[0][nr][nc] == -2 ? 0 : mark[0][nr][nc];
                int b = mark[1][nr][nc] == -2 ? 0 : mark[1][nr][nc];
                mark[i][r][c] = (a + b) % MOD;
//                mark[i][r][c] = (mark[0][nr][nc] % MOD) + (mark[1][nr][nc] % MOD);
            }
            else if(map[nr][nc] == -1) // 도착지점
            {
                mark[i][r][c] = 1;
            }
            else if(map[nr][nc] == 2)
            {
                mark[i][r][c] = mark[i][nr][nc] % MOD;
            }
        }
        else
        {
            if(nr >= 0 && nr < M && nc >= 0 && nc < N && map[nr][nc] == 0) mark[i][r][c] = mark[(i+1)%2][nr][nc];
            else mark[i][r][c] = -2;
        }
    }
    return isPossible;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    M = m; N = n;
    map = city_map;
    MOD = 20170805;
    vector<vector<vector<int>>> mark(2, vector<vector<int>>(510, vector<int>(510,0)));


    if(M == 1 && N == 1) return 0;
    map[M-1][N-1] = -1;
    mark[0][M-1][N-1] = 1;
    mark[1][M-1][N-1] = 1;

    dfs(0,0,-1, mark);

//    Print();
    int a = mark[0][0][0] < 0 ? 0 : mark[0][0][0];
    int b = mark[1][0][0] < 0 ? 0 : mark[1][0][0];
    answer = (a + b) % MOD;
//    cout << answer;
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