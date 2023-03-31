#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000

long long G;

int main() {
    bool found = false;
    cin >> G;

    for (long long cur = 1; cur <= MAX; cur++) {
        long long num = (cur * cur) - G; // num = prev * prev
        if(num <= 0 || num >= cur*cur) continue;

        double res = sqrt(num);
        if(res == floor(res)) {
            found = true;
            cout << cur << '\n';
        }
    }

    if(!found) cout << -1;
}