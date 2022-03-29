#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int arr[110][110];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<int> answer;

int bfs(int r, int c)
{
    int cnt = 1;
    arr[r][c] = -1; // 방문 체크 -1
    queue<pair<int,int>> q;
    q.push({r,c});

    while(!q.empty())
    {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];
            if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= M) continue;
            // 직사각형으로 채워져있거나 이미 방문
            if(arr[nnr][nnc] == 1 || arr[nnr][nnc] == -1) continue;
            arr[nnr][nnc] = -1;
            q.push({nnr, nnc});
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int y = y1; y < y2; y++)
        {
            for(int x = x1; x < x2; x++)
            {
                arr[x][y] = true;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] == 0) answer.push_back(bfs(i,j));
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for(auto x : answer) cout << x << ' ';
}