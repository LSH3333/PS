#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int ans;
int arr[55][55];
int mark[55][55];
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int r, int c)
{
    queue<pair<int,int>> q;
    q.push({r,c});
    mark[r][c] = 1;

    while(!q.empty())
    {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();
        // 최단거리 구함
        if(arr[nr][nc] == 1)
        {
            //cout << r << ' ' << c << endl;
            //cout << nr << ' ' << nc << ", cnt = " << mark[nr][nc] << endl << endl;
            ans = max(ans, mark[nr][nc]-1);
            break;
        }
        for(int i = 0; i < 8; i++)
        {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];

            if(nnr < 0 || nnr > N || nnc < 0 || nnc > M) continue;
            if(mark[nnr][nnc] != 0) continue; // 이미 방문
            q.push({nnr,nnc});
            mark[nnr][nnc] = mark[nr][nc] + 1; // +1 칸
        }
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] == 1) continue;
            bfs(i, j);
            fill(&mark[0][0], &mark[52][52], 0);
            //memset(mark, 0, sizeof(mark));
        }
    }

    cout << ans;
}