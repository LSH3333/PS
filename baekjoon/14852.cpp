#include <iostream>
using namespace std;

#define MOD 1000000007
int N;
long long d[1000010];
long long sums[1000010];

int main() {
    cin >> N;

    d[0] = 1;
    d[1] = 2;
    d[2] = 7;
    sums[1] = 1;

    for(int i = 3; i <= N; i++) {
        sums[i] = (d[i-3] + sums[i-1]) % MOD;
        d[i] = ((d[i - 1] * 2) + (d[i - 2] * 3) + (sums[i] * 2)) % MOD;
    }

    cout << d[N] % MOD;
}