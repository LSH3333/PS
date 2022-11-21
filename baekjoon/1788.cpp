#include <iostream>
using namespace std;

int N;
int d[1000010];
#define MOD 1000000000

int positive(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(d[n] > 0) return d[n];
    return d[n] = (positive(n-1) + positive(n-2)) % MOD;
}


int main() {
    cin >> N;

    if(N == 0) {
        cout << 0 << '\n' << 0;
    }
    else if(N > 0) {
        cout << 1 << '\n';
        cout << positive(N);
    }
    else {
        d[1] = 1;
        N *= -1;
        for(int i = 2; i <= N; i++) {
            d[i] = (d[i-2] - d[i-1]) % MOD;
        }
        if(d[N] == 0) {
            cout << 0;
        }
        else if(d[N] > 0) {
            cout << 1 << '\n';
            cout << d[N] % MOD;
        }
        else {
            cout << -1 << '\n';
            cout << abs(d[N]) % MOD;
        }
    }
}