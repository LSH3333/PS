#include <iostream>
using namespace std;

int main() {
    int card[1001];
    int d[1001] = {0};

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> card[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            d[i] = max(d[i], d[j] + card[i-j]);
        }
    }

    cout << d[n];

}