#include <iostream>
#include <cstdio>
using namespace std;

int a[100010];
int d[3][100010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];

    int answer = -1000000000;
    d[0][0] = a[0];
    for(int i = 1; i < N; i++)
    {
        d[0][i] = max(d[0][i-1] + a[i], a[i]);
        answer = max(answer, d[0][i]);
    }

    for(int i = 1; i < N; i++)
    {
        d[1][i] = max(d[1][i-1], d[2][i-1]) + a[i];
        answer = max(answer, d[1][i]);
        d[2][i] = d[0][i-2] + a[i];
        answer = max(answer, d[2][i]);
    }

    cout << answer;
}