#include <iostream>
#include <queue>
using namespace std;

int n;
int r1,c1,r2,c2;
bool mark[201][201];
int dr[] = {-2, -2, 0, 0, 2, 2};
int dc[] = {-1, 1, -2, 2, -1, 1};

int bfs()
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{r1,c1}, 0});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(r == r2 && c == c2) return cnt;

        for(int i = 0; i < 6; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if(mark[nr][nc]) continue;
            mark[nr][nc] = true;
            q.push({{nr,nc}, cnt+1});
        }

    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> r1 >> c1 >> r2 >> c2;;

    cout << bfs();
}