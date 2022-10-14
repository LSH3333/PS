#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;

    while(t--)
    {
        int m, n, x, y, a = 0, b = 0;
        cin >> m >> n >> x >> y;

        int add = y-1;
        int cnt = 1;

        while(cnt <= m * n)
        {
            if(a == x - 1 && b == y - 1) break;
            // 일수 카운팅, 첫 진행시 주이진 일로 고정 시킴
            cnt += add;
            a = (a + add) % m;
            b = (b + add) % n;
            // 일로 고정된후에는 월 증가시킴
            add = n;
        }
        int ans = cnt > m * n ? -1 : cnt;
        cout << ans << '\n';
    }

}