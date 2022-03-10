#include <iostream>
#include <algorithm>
using namespace std;

int d[10010];
int money[110];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> money[i];
    }

    d[0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            if(j - money[i] < 0) continue; // 범위
            d[j] += d[j - money[i]];
        }
    }

    cout << d[k];
}