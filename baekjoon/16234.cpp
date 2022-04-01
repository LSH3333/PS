#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, L, R;
int board[51][51];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer = 0;


// 인구 변화 있을시 return true, else false
bool bfs(int _r, int _c, vector<vector<bool>> &mark)
{
    vector<pair<int,int>> v;
    int sum = 0;
    queue<pair<int,int>> q;
    mark[_r][_c] = true;
    q.push({_r, _c});
    sum += board[_r][_c];

    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        v.push_back({r,c});
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(mark[nr][nc]) continue;
            // 경계를 공유하는 두 나라의 인구 차이
            int sub = abs(board[r][c]-board[nr][nc]);
            if(sub >= L && sub <= R)
            {
                sum += board[nr][nc];
                mark[nr][nc] = true;
                q.push({nr,nc});
            }
        }
    }

    if(v.size() == 1) return false;
    int res = sum / v.size();
    for(auto x : v)
    {
        board[x.first][x.second] = res;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    while(true)
    {
        vector<vector<bool>> mark(51, vector<bool>(51, false));
        bool changed = false;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(mark[i][j]) continue;
                // 변경 한번이라도 있으면 기록
                if(bfs(i, j, mark)) changed = true;
            }
        }

        // 인구 변경 없었다면 종료
        if(!changed) { cout << answer; return 0; }
        else answer++; // 인구 변경 있었다면 일수 증가
    }

}