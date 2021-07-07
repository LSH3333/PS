#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d[10];

    for(int i = 0; i < n; i++) {
        d[i] = i + 1;
    }


    do {
        for(int i = 0; i < n; i++) {
            cout << d[i] << ' ';
        }
        cout << '\n';
    } while(next_permutation(d, d+n));
}