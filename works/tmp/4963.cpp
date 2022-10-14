#include <iostream>
#include <vector>
using namespace std;

int w, h;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c, vector<vector<int>> &arr, vector<vector<bool>> &mark)
{
    if(mark[r][c]) return;

    mark[r][c] = true;
    for(int i = 0; i < 8; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
        if(arr[nr][nc] != 1) continue;
        dfs(nr, nc, arr, mark);
    }
}

int main()
{
    while(true)
    {
        int ans = 0;
        cin >> w >> h;
        if(w == 0 && h == 0) return 0;

        vector<vector<int>> arr(51, vector<int>(51,0));
        vector<vector<bool>> mark(51, vector<bool>(51, false));

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                cin >> arr[i][j];
            }
        }

        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(arr[i][j] != 1 || mark[i][j]) continue;
                dfs(i, j, arr, mark);
                ans++;
            }
        }
        cout << ans << '\n';
    }

}