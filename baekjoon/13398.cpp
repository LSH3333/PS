#include <iostream>
using namespace std;

int a[100010];
int d[2][100010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    int answer = a[0];
    d[0][0] = a[0];
    d[1][0] = 0;

    for(int i = 1; i < n; i++)
    {
        d[0][i] = max(d[0][i-1] + a[i], a[i]);
        d[1][i] = max(max(d[0][i-1], d[1][i-1]) + a[i], d[0][i-1]);
        answer = max(answer, d[0][i]);
        answer = max(answer, d[1][i]);
    }

    cout << answer;
}