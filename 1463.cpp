#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d[1000001];

    d[0] = 0; // base
    d[1] = 0;

    for(int i = 2; i <= n; i++) {
        int val = d[i-1] + 1;
        if(i % 2 == 0) val = min(d[i/2] + 1, val);
        if(i % 3 == 0) val = min(d[i/3]+1, val);

        d[i] = val;
    }

    cout << d[n];


}