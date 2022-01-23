#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<string> map;
bool mark[110][110];
int n, m, answer = 2000000000;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<pair<int,int>, int>> q;
    mark[0][0] = true;
    q.push({{0,0}, 1});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        if(r == n-1 && c == m-1)
        {
            answer = min(answer, depth);
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(mark[nr][nc] || map[nr][nc] == '0') continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, depth+1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string str; cin >> str;
        map.push_back(str);
    }

    bfs();

    cout << answer;
}