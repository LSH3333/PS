#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string arr[2];
bool mark[2][200010];
int n, k;

bool bfs()
{
    // r, c, time
    queue<pair<pair<int,int>, int>> q;
    q.push({{0, 0}, 0});

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if(c >= n) return true;
        mark[r][c] = true;

        // 한칸 앞으로 이동
        // 다음 이동이 조건 통과고 도착이면 바로 트루 리턴
        if(c+1 >= time+1 && c+1 >= n) return true;
        if(c+1 >= time+1 && arr[r][c+1] != '0' && !mark[r][c+1])
        {
            mark[r][c+1] = true;
            q.push({{r, c+1}, time+1});
        }

        // 한칸 뒤로 이동
        if(c-1 >= time+1 && c-1 >= 0 && arr[r][c-1] != '0' && !mark[r][c-1])
        {
            mark[r][c-1] = true;
            q.push({{r, c-1}, time+1});
        }
        // 옆칸 이동
        int nr = r == 0 ? 1 : 0;
        if(c+k >= time+1 && c+k >= n) return true;
        if(c+k >= time+1 && arr[nr][c+k] != '0' && !mark[nr][c+k])
        {
            mark[nr][c+k] = true;
            q.push({{nr, c+k}, time+1});
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < 2; i++)
    {
        string s; cin >> s;
        arr[i] = s;
    }

    cout << bfs();

}