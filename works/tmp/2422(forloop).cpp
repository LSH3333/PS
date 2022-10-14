#include <iostream>
#include <bitset>
using namespace std;

bool mark[201][201];

int main()
{
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int a, b;
        cin >> a >> b;
        mark[a][b] = true;
        mark[b][a] = true;
    }

    int cnt = 0;
    for(int i = 1; i <= n - 2; i++)
    {
        for(int j = i + 1; j <= n - 1; j++)
        {
            for(int k = j + 1; k <= n; k++)
            {
                if(mark[i][j] || mark[j][k] || mark[k][i]) continue;
                cnt++;
            }
        }
    }
    cout << cnt;
}