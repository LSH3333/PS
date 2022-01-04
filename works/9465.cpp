#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int d[3][100010] = {0,};
        int a[2][100010];

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

        // 0열 위에 땠을때 최대값
        d[0][0] = a[0][0];
        // 0열 아래 땠을때 최대값
        d[1][0] = a[1][0];
        // 0-1열을 안땐경우, 0열은 위 아래 중 아무곳이나 때도됨
        d[2][0] = max(a[0][0], a[1][0]);

        d[0][1] = a[0][1] + d[1][0];
        d[1][1] = a[1][1] + d[0][0];
        d[2][1] = max(a[0][1], a[1][1]);

        for (int i = 2; i < n; i++)
        {
            // 위에 땜
            d[0][i] = a[0][i] + max(d[1][i - 1], max(d[0][i-2],max(d[1][i-2],d[2][i-2])));
            // 아래 땜
            d[1][i] = a[1][i] + max(d[0][i - 1], max(d[0][i-2],max(d[1][i-2],d[2][i-2])));
            // 이전을 안땠으므로 전전열 최댓값 + 현재 열 최댓값
            d[2][i] = max(d[0][i - 2], max(d[1][i - 2], d[2][i - 2])) + max(a[0][i], a[1][i]);
        }

        cout << max(d[0][n-1], max(d[1][n-1], d[2][n-1])) << '\n';
    }
}