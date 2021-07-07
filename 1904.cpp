#include <iostream>
using namespace std;

long long d[1000001];

long long pibo(int n) {
    // base
    if(n <= 1) return n;

    // memoization
    if(d[n] > 0) return d[n];

    d[n] = (pibo(n-1) + pibo(n-2)) % 15746;
    return d[n];
}

int main() {
    int n;
    cin >> n;

    cout << pibo(n+1) << '\n';

}