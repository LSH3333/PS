#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][3];
int d[1001][3];

int main()
{
    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    d[0][0] = a[0][0];
    d[0][1] = a[0][1];
    d[0][2] = a[0][2];

    for(int i = 1; i < n; i++)
    {
        d[i][0] = min(d[i-1][1], d[i-1][2]) + a[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + a[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + a[i][2];
    }

    cout << *min_element(d[n-1], d[n-1]+3);
}