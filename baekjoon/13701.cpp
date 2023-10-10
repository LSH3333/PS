#include <iostream>
#include <bitset>
using namespace std;

// 1000000000000000000000000(2), 2^25
bitset<(1 << 25)> mask;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    while(cin >> n) {
        if (!mask[n]) {
            cout << n << ' ';
            mask[n] = true;
        }
    }
}