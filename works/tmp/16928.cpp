#include <iostream>
#include <queue>
using namespace std;

int n, m;
bool mark[101];
// 인덱스에서 값으로 이동, moveTo[2]=3이면 2에서3으로 이동
int moveTo[101];
int answer;

void bfs()
{
    // cur, cnt
    queue<pair<int,int>> q;
    q.push({1, 0});

    while(!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(cur == 100)
        {
            answer = cnt;
            break;
        }
        for(int i = 1; i <= 6; i++)
        {
            int ncur = cur + i;
            if(ncur > 100 || mark[ncur]) continue;
            // 다음 칸이 사다리 or 뱀
            if(moveTo[ncur] != 0)
            {
                // 사다리, 뱀 타고 이동
                ncur = moveTo[ncur];
                mark[ncur] = true;
                q.push({ncur, cnt+1});
            }
            else
            {
                mark[ncur] = true;
                q.push({ncur, cnt+1});
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n+m; i++)
    {
        int a, b; cin >> a >> b;
        moveTo[a] = b;
    }

    bfs();
    cout << answer;
}