#include <iostream>
using namespace std;

int N, M;
int train[50010];
// ???
int preSum[50010];
int d[4][50010];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> train[i];
        preSum[i] = preSum[i-1] + train[i];
    }
    cin >> M;

    for(int i = 1; i <= 3; i++) {
        for(int j = i*M; j <= N; j++) {
            int sum = preSum[j] - preSum[j - M];
            d[i][j] = max(d[i - 1][j - M] + sum, d[i][j - 1]);
        }
    }

    cout << d[3][N];
}