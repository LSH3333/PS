#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool mark[4000];

int bfs(int S)
{
    // 현재 이모티콘 수, 클립보드에 복사된 이모티콘 수, 시간
    queue<pair<pair<int,int>,int>> q;
//    mark[1] = true;
    q.push({{1, 0}, 0});

    while(!q.empty())
    {
        int cur = q.front().first.first;
        int clipBoard = q.front().first.second;
        int time = q.front().second;
        q.pop();
//        cout << cur << ' ' << clipBoard << ' ' << time << endl;
        if(cur == S) { return time; }

        // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
        if(!mark[cur])
        {
            mark[cur] = true;
            q.push({{cur, cur}, time+1});
        }

        // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
        if(clipBoard > 0)
        {
            q.push({{cur+clipBoard, clipBoard}, time+1});
        }

        // 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
        if(cur-1 >= 1)
        {
            q.push({{cur-1, clipBoard}, time+1});
        }

    }

    return 0;
}

int main()
{
    int S; cin >> S;
    cout << bfs(S);
}