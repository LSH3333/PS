#include <iostream>
using namespace std;

#define MOD 1000000007
int d[55];

int main() {
    int N; cin >> N;
    d[0] = 1;
    d[1] = 1;
    for(int i = 2; i <= 50; i++) {
        d[i] = (d[i-1] + d[i-2] + 1) % MOD;
    }
    cout << d[N];
}