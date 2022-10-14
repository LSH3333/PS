#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--)
    {
        int a[2][100010] = {0,}, d[3][100010] = {0,};
        int n; cin >> n;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }

        // 가로 크기가 1인 스티커에서의 최대점수
        // 마지막(1열)에서 위를 땠을때
        d[0][1] = a[0][1];
        // 아래를 땠을때
        d[1][1] = a[1][1];
        // 안땠을때
        d[2][1] = 0;

        for(int i = 2; i <= n; i++)
        {
            d[0][i] = max(d[1][i-1], d[2][i-1]) + a[0][i];
            d[1][i] = max(d[0][i-1], d[2][i-1]) + a[1][i];
            d[2][i] = max(d[0][i-1], max(d[1][i-1], d[2][i-1]));
        }

        cout << max(d[0][n], max(d[1][n], d[2][n])) << '\n';
    }

}