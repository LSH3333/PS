#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int N, num;
int ansR, ansC;

void dfs(int r, int c, int cnt, int dir, vector<vector<int>> &v)
{
    if(cnt == 0) return;
    if(cnt == num) { ansR = r; ansC = c; }

    v[r][c] = cnt;
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    if(nr < 0 || nr >= N || nc < 0 || nc >= N || v[nr][nc] != 0)
    {
        dir = (dir + 1) % 4;
        nr = r + dr[dir];
        nc = c + dc[dir];
    }

    dfs(nr, nc, cnt-1, dir, v);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> num;

    vector<vector<int>> v(N, vector<int>(N, 0));
    dfs(0, 0, N*N, 0, v);

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ansR+1 << ' ' << ansC+1;
}