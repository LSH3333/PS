#include <iostream>
#include <vector>
using namespace std;

int N;
int d[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    // 0 : ?? ?, 1 : ?? ?
    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    d[4] = 1;

    for(int i = 5; i <= N; i++) {
        if (d[i - 1] == 0 || d[i - 3] == 0 || d[i - 4] == 0) {
            d[i] = 1;
        }
    }

    if (d[N] == 1) {
        cout << "SK";
    } else {
        cout << "CY";
    }
}