#include <iostream>
using namespace std;

int a[510][510];
int d[510][510];

int main() {
    int N;
    cin >> N;
    for(int r = 1; r <= N; r++) {
        for(int c = 1; c <= r; c++) {
            cin >> a[r][c];
        }
    }

    d[1][1] = a[1][1];
    for(int r = 2; r <= N; r++) {
        for(int c = 1; c <= r; c++) {
            d[r][c] = a[r][c] + max(d[r-1][c-1], d[r-1][c]);
        }
    }

    int answer = d[N][1];
    for(int c = 1; c <= N; c++) {
        answer = max(answer, d[N][c]);
    }

    cout << answer;
}