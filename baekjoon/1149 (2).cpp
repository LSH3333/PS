#include <iostream>
using namespace std;

int N;
int a[1010][3];
int d[1010][3];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    d[0][0] = a[0][0];
    d[0][1] = a[0][1];
    d[0][2] = a[0][2];

    for(int r = 1; r < N; r++) {
        d[r][0] = a[r][0] + min(d[r - 1][1], d[r - 1][2]);
        d[r][1] = a[r][1] + min(d[r - 1][0], d[r - 1][2]);
        d[r][2] = a[r][2] + min(d[r - 1][0], d[r - 1][1]);
    }

    cout << min(min(d[N - 1][0], d[N - 1][1]), d[N - 1][2]);
}