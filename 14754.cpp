#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
long long h[1010][1010];
bool mark[1010][1010];
long long ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> h[i][j];
            ans += h[i][j];
        }
    }

    // row
    for(int i = 0; i < n; i++)
    {
        long long biggest = 0;
        int biggestIdx = 0;
        // col
        for(int j = 0; j < m; j++)
        {
            if(h[i][j] > biggest)
            {
                biggest = h[i][j];
                biggestIdx = j;
            }
        }
        // 열에서 최댓값 찾을때 중복방지 위해
        mark[i][biggestIdx] = true;
        // 각 행에서 가장 큰 값 뺌
        ans -= biggest;
    }

    // col
    for(int i = 0; i < m; i++)
    {
        long long biggest = 0;
        int biggestIdx = 0;
        // row
        for(int j = 0; j < n; j++)
        {
            if(h[j][i] > biggest)
            {
                biggest = h[j][i];
                biggestIdx = j;
            }
        }

        // 행 최댓값과 중복되면 빼지않음
        if(!mark[biggestIdx][i])
        {
            ans -= biggest;
        }

    }
    cout << ans;
}