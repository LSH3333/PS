#include <iostream>
using namespace std;

int N;
int a[310];
int d[310][2];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    d[1][0] = a[1];
    d[1][1] = a[1];

    for(int i = 2; i <= N; i++) {
        d[i][0] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][0], d[i-2][1]) + a[i];
    }

    cout << max(d[N][0], d[N][1]);
}