#include <iostream>
#include <cmath>
using namespace std;

// 남은 거리, 바로전에 이동한 거리, 카운트 
long long dfs(long long distance, long long moved, long long cnt)
{
    if(distance == 0) return cnt;
//    cout << "dis: " << distance << ' ' << "moved: " << moved << ' ' << "cnt: " << cnt << endl;

    for(long long move = moved+1; move >= moved-1; move--)
    {
        if(move <= 0) continue;
        long long sum = (move * (move + 1)) / 2;
        if(sum <= distance)
        {
            return dfs(distance-move, move, cnt+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        long long x, y; cin >> x >> y;
        long long distance = y - x;
        long long ans = dfs(distance, 0, 0);
        cout << ans << '\n';
    }

}