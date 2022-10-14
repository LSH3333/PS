#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;
bool mark[100010];
int dv[] = {-1, 1, 2};

int bfs()
{
    queue<pair<int,int>> q;
    q.push({N,0});
    mark[N] = true;

    while(!q.empty())
    {
        int v = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(v == K)
            return depth;

        for(int i = 0; i < 3; i++)
        {
            int nv;
            if(i == 2) nv = v * dv[i];
            else nv = v + dv[i];

            if(nv < 0 || nv > 100000) continue;
            if(mark[nv]) continue;
            q.push({nv, depth+1});
            mark[nv] = true;
        }
    }

}

int main()
{
    cin >> N >> K;
    cout << bfs();
}