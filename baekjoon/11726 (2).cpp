#include <iostream>
using namespace std;

#define MOD 10007

int N;
int d[1010];

int main() {
    cin >> N;
    d[1] = 1;
    d[2] = 2;

    for(int i = 3; i <= N; i++) {
        d[i] = (d[i-1] + d[i-2]) % MOD;
    }

    cout << d[N] % MOD;
}