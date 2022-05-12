#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 추가 되는 양분의 양
int A[11][11];
// 각 칸의 나무들의 나이
vector<int> trees[11][11];
// 각 칸의 양분
int food[11][11];

int N, M, K;
// 가을 번식에 의해 심어질 나무들의 중심 위치, 하나의 좌표에 의해 8개의 아기나무들 생김
vector<pair<int,int>> babyTree;


void SpringSummer()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(trees[i][j].empty()) continue;
            sort(trees[i][j].begin(), trees[i][j].end());

            int idx; // 얘부터 죽은 나무
            for(idx = 0; idx < trees[i][j].size(); idx++)
            {
                if(trees[i][j][idx] > food[i][j]) break;
                food[i][j] -= trees[i][j][idx];
            }

            // summer
            for(int a = idx; a < trees[i][j].size(); a++)
            {
                // 봄에 죽은 나무들이 양분으로
                food[i][j] += trees[i][j][a] / 2;
            }

            // 죽은 나무들 제거
            while(trees[i][j].size() > idx) trees[i][j].pop_back();

            for(auto &x : trees[i][j])
            {
                x++;
                if(x % 5 == 0) babyTree.push_back({i,j});
            }
        }
    }
}

void Fall()
{
    for(auto x : babyTree)
    {
        int r = x.first; int c = x.second;
        if(r-1 > 0) trees[r-1][c].push_back(1);
        if(r-1 > 0 && c+1 <= N) trees[r-1][c+1].push_back(1);
        if(c+1 <= N) trees[r][c+1].push_back(1);
        if(r+1<=N && c+1<=N) trees[r+1][c+1].push_back(1);
        if(r+1<=N) trees[r+1][c].push_back(1);
        if(r+1<=N && c-1>0) trees[r+1][c-1].push_back(1);
        if(c-1 > 0) trees[r][c-1].push_back(1);
        if(r-1>0 && c-1>0) trees[r-1][c-1].push_back(1);
    }
    babyTree.clear();
}

void Winter()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            food[i][j] += A[i][j];
        }
    }
}

void OneYear()
{
    SpringSummer();
    Fall();
    Winter();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            food[i][j] = 5;
        }
    }
    for(int i = 0; i < M; i++)
    {
        int x,y,z; cin >> x >> y >> z;
        trees[x][y].push_back(z);
    }



    for(int i = 0; i < K; i++) OneYear();

    int cnt = 0;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(trees[i][j].empty()) continue;
            cnt += trees[i][j].size();
        }
    }
    cout << cnt;
}