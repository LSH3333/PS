#include <iostream>
using namespace std;


long long d[40];

long long T(long long n) {
    if(d[n] > 0) return d[n];

    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += T(i) * T(n-(i+1));
    }

    return d[n] = res;
}

int main()
{
    int N;
    cin >> N;
    d[0] = 1;
    cout << T(N);
}