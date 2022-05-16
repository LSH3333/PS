#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, D;
int enemy[20][20];

// left up right
int dr[] = {0, -1, 0};
int dc[] = {-1, 0, 1};

void CalDistance(vector<vector<int>> &v, int _r, int _c)
{
    queue<pair<pair<int,int>,int>> q;
    q.push({{_r,_c}, 1});
    v[_r][_c] = 1;

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int depth = q.front().second;
        q.pop();

        for(int i = 0; i < 3; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nc < 0 || nc >= M) continue;
            if(v[nr][nc] != 0) continue;
            v[nr][nc] = depth;
            q.push({{nr,nc}, depth+1});
        }
    }
}

void Print(vector<vector<int>> &v)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << v[i][j] << ' ';
        }cout<< endl;
    }
}

int main()
{
    cin >> N >> M >> D;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            cin >> enemy[i][j];
        }
    }

//    vector<vector<int>> v(20, vector<int>(20, 0));
//    CalDistance(v, N, 0);
//    Print(v);

    vector<int> archers(M);
    for(int i = 0; i < 3; i++) archers[i] = 1;
    do
    {
        for(auto x : archers) cout << x << ' '; cout << endl;
    } while(prev_permutation(archers.begin(), archers.end()));



}