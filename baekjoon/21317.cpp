#include <iostream>
using namespace std;

int N, K;
int jump[2][22];
int d[2][22];

int main() {
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cin >> jump[0][i] >> jump[1][i];
        d[0][i] = 1000000;
        d[1][i] = 1000000;
    }
    d[0][N-1] = 1000000;
    d[1][N-1] = 1000000;
    cin >> K;

    d[0][0] = 0;
    d[1][0] = 0;
    for(int i = 0; i < N-1; i++) {
        // 매우 큰 점프 아직 사용 하지 않았을 경우
        d[0][i+1] = min(d[0][i+1], d[0][i] + jump[0][i]);
        if(i+2 < N)
            d[0][i+2] = min(d[0][i+2], d[0][i] + jump[1][i]);
        if(i+3 < N)
            d[1][i+3] = min(d[1][i+3], d[0][i] + K);

        // 매우 큰 점프 이미 사용 했을 경우
        d[1][i+1] = min(d[1][i+1], d[1][i] + jump[0][i]);
        if(i+2 < N)
            d[1][i+2] = min(d[1][i+2], d[1][i] + jump[1][i]);
    }
    
    cout << min(d[0][N - 1], d[1][N - 1]);
}