#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> m;

long long Cal(long long n) {
    if(n == 0) return 1;
    if(m[n] != 0) return m[n];

    long long res = Cal(n / P) + Cal(n / Q);
    m[n] = res;
    return res;
}

int main() {
    cin >> N >> P >> Q;
    cout << Cal(N);
}