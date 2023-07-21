#include <iostream>
using namespace std;

long long N, res;
long long a[110];
long long d[110][21];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(i == N-1) {
            res = a[i];
        }
    }

    d[0][a[0]] = 1;

    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j <= 20; j++) {
            long long val = a[i+1];
            if(d[i][j] > 0) {
                if(j-val >= 0) {
                    d[i+1][j-val] += d[i][j];
                }
                if(j+val <= 20) {
                    d[i+1][j+val] += d[i][j];
                }
            }
        }
    }

    cout << d[N-2][res];
}