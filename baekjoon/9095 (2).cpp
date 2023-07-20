#include <iostream>
using namespace std;

int d[11];

int main() {

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i <= 10; i++) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    int T;
    cin >> T;
    while(T--) {
        int N; cin >> N;
        cout << d[N] << '\n';
    }
}