#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<string> map;
int mark[30][30];
int N;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<int> answer;

void bfs(int r, int c, int cnt)
{
    queue<pair<int,int>> q;
    mark[r][c] = cnt;
    q.push({r,c});
    int numberOfHouse = 1;
    while(!q.empty())
    {
        int nr = q.front().first;
        int nc = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nnr = nr + dr[i];
            int nnc = nc + dc[i];
            if(nnr < 0 || nnr >= N || nnc < 0 || nnc >= N) continue;
            if(mark[nnr][nnc] > 0 || map[nnr][nnc] == '0') continue;
            mark[nnr][nnc] = cnt;
            q.push({nnr,nnc});
            numberOfHouse++;
        }
    }
    answer.push_back(numberOfHouse);
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string tmp; cin >> tmp;
        map.push_back(tmp);
    }

    int cnt = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] == '1' && mark[i][j] == 0)
            {
                bfs(i, j, cnt);
                cnt++;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << cnt-1 << ' ';
    for(auto x : answer) cout << x << ' ';
}