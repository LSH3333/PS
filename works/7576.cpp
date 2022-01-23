#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int map[1010][1010];
int mark[1010][1010];
int N, M;
vector<pair<int,int>> location;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int answer;

void bfs()
{
    queue<pair<pair<int,int>, int>> q;
    for(auto x : location)
    {
        q.push({{x.first,x.second}, 1});
        mark[x.first][x.second] = 1;
    }

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(map[nr][nc] == -1 || mark[nr][nc] > 0) continue;
            mark[nr][nc] = depth+1;
            q.push({{nr,nc}, depth+1});
            answer = max(answer, depth+1);
        }
    }
}

int main()
{

    cin >> M >> N;
    int numOfZero = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1) location.push_back({i,j});
            if(map[i][j] == -1) mark[i][j] = -1;
            if(map[i][j] == 0) numOfZero++;
        }
    }
    if(numOfZero == 0) {cout << 0; return 0;}
    bfs();

    bool success = true;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(mark[i][j] == 0) { success = false; break;}
        }
    }

    if(!success) cout << -1;
    else cout << answer-1;
}