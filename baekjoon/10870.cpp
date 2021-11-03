#include <iostream>
using namespace std;

int d[21];

/// top-down
int pibo(int n) {
    /// base
    if(n <= 1) return n;
    if(d[n] > 0) return d[n]; /// memoization
    return d[n] = pibo(n-1) + pibo(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << pibo(n);

}