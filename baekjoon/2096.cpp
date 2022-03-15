#include <iostream>
#include <algorithm>
using namespace std;

int a[100001][3];
int d[2][3];
int maxAns, minAns;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
    }

    // 최대
    d[0][0] = a[0][0];
    d[0][1] = a[0][1];
    d[0][2] = a[0][2];
    int targetR = 0;
    for(int i = 1; i < N; i++)
    {
        int curR = (targetR + 1) % 2;
        d[curR][0] = max(d[targetR][0] + a[i][0], d[targetR][1] + a[i][0]);
        d[curR][1] = max(d[targetR][0] + a[i][1], max(d[targetR][1] + a[i][1], d[targetR][2] + a[i][1]));
        d[curR][2] = max(d[targetR][1] + a[i][2], d[targetR][2] + a[i][2]);
        targetR = (targetR + 1) % 2;
    }
    maxAns = *max_element(&d[targetR][0], &d[targetR][0] + 3);

    // 최소
    d[0][0] = a[0][0];
    d[0][1] = a[0][1];
    d[0][2] = a[0][2];
    targetR = 0;
    for(int i = 1; i < N; i++)
    {
        int curR = (targetR + 1) % 2;
        d[curR][0] = min(d[targetR][0] + a[i][0], d[targetR][1] + a[i][0]);
        d[curR][1] = min(d[targetR][0] + a[i][1], min(d[targetR][1] + a[i][1], d[targetR][2] + a[i][1]));
        d[curR][2] = min(d[targetR][1] + a[i][2], d[targetR][2] + a[i][2]);
        targetR = (targetR + 1) % 2;
    }
    minAns = *min_element(&d[targetR][0], &d[targetR][0] + 3);

    cout << maxAns << ' ' << minAns;

}
