#include <iostream>
using namespace std;

int d[41];

int Fibonacci(int n){
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }
    if(d[n] > 0) {
        return d[n];
    }
    return d[n] = Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    d[1] = 1;
    Fibonacci(40);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        if(N == 0) { cout << 1 << ' ' << 0 << '\n';}
        else if(N == 1) { cout << 0 << ' ' << 1 << '\n'; }
        else cout << d[N-1] << ' ' << d[N] << '\n';
    }
}