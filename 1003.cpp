#include <iostream>
using namespace std;

int d[101] = {0,1,};

int fibonacci(int n) {
    // base
    if(n == 0) {   return 0; }
    if(n == 1) {   return 1; }

    // memoization!!
    if(d[n] > 0) {  return d[n]; }


    d[n] = fibonacci(n-1) + fibonacci(n - 2);
    return d[n];
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        fibonacci(n);

        if(n == 0) cout << "1 " << "0" << '\n';
        else if(n == 1) cout << "0 " << "1" << '\n';
        else cout << d[n-1] << ' ' << d[n] << '\n';

    }
}