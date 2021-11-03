#include <iostream>
using namespace std;
#include <algorithm>

int wine[10001];
int d[10001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> wine[i];

    d[0] = 0;
    d[1] = wine[1];
    d[2] = wine[1] + wine[2];

    for(int i = 3; i <= n; i++) {
        d[i] = max({d[i-1], d[i-2]+wine[i], d[i-3]+wine[i-1]+wine[i]});
    }

    cout << d[n];
}