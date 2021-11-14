#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;

    int score[302];
    int d[302][2];

    for(int i = 1; i <= n; i++)
        cin >> score[i];

    score[0] = 0;
    d[0][0] = 0;
    d[0][1] = 0;
    d[1][0] = score[1];
    d[1][1] = score[1];

    for(int i = 2; i <= n; i++)
    {
        d[i][0] = d[i-1][1] + score[i];
        d[i][1] = max(d[i-2][0], d[i-2][1]) + score[i];
    }

    cout << max(d[n][0], d[n][1]);
}