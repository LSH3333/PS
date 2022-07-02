#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;

int bfs()
{
    if(S == G) return 0;
    queue<pair<int,int>> q;
    vector<bool> mark(F+1, false);
    q.push({S, 0});
    mark[S] = true;

    while(!q.empty())
    {
        int cur = q.front().first;
        int depth = q.front().second;
        q.pop();
        // UP
        int nextUp = cur + U;
        if(nextUp == G) return depth+1;
        else if(nextUp < F && !mark[nextUp]) { q.push({nextUp, depth+1}); mark[nextUp] = true; }

        // DOWN
        int nextDown = cur - D;
        if(nextDown == G) return depth+1;
        else if(nextDown >= 1 && !mark[nextDown]) { q.push({nextDown, depth+1}); mark[nextDown] = true; }

    }
    return -1;
}

int main()
{
    cin >> F >> S >> G >> U >> D;
    int ret = bfs();
    if(ret == -1) cout << "use the stairs";
    else cout << ret;

}