#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[5][5];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
pair<int,int> lists[] =
        {
                {0,0}, {0,1}, {0,2}, {0,3}, {0,4},
                {1,0}, {1,1}, {1,2}, {1,3}, {1,4},
                {2,0}, {2,1}, {2,2}, {2,3}, {2,4},
                {3,0}, {3,1}, {3,2}, {3,3}, {3,4},
                {4,0}, {4,1}, {4,2}, {4,3}, {4,4}
        };
int answer;

int bfs(const vector<int> &v)
{
    // true시 이동 가능 지점
    vector<vector<bool>> mark(5, vector<bool>(5, false));
    for(auto x : v)
    {
        int r = lists[x].first, c = lists[x].second;
        mark[r][c] = true;
    }

    vector<vector<bool>> visited(5, vector<bool>(5, false));
    queue<pair<int,int>> q;
    int _r = lists[v.front()].first, _c = lists[v.front()].second;
    visited[_r][_c] = true;
    q.push({_r,_c});

    while(!q.empty())
    {
        int r = q.front().first, c = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
            if(!mark[nr][nc] || visited[nr][nc]) continue;
            q.push({nr,nc});
            visited[nr][nc] = true;
        }
    }

    // 선택된 조합 지점 모두 방문했는지 확인
    int Scnt = 0, Ycnt = 0;
    for(auto x : v)
    {
        int r = lists[x].first, c = lists[x].second;
        if(board[r][c] == 'S') Scnt++; else Ycnt++;
        if(!visited[r][c]) return -1;
    }
    return Scnt;
}

void dfs(int idx, vector<int> &v, vector<bool> &visited)
{
    // 7개 뽑은 조합
    if(v.size() == 7)
    {
        // 선택 조합 지점 모두 방문 했다면 7지점이 인접하다
        if(bfs(v) >= 4)
        {
            answer++;
        }
        return;
    }

    for(int i = idx; i < 25; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs(i, v, visited);
        visited[i] = false;
        v.pop_back();
    }

}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> v;
    vector<bool> visited(25, false);
    dfs(0, v, visited);

    cout << answer;
}