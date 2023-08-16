#include <iostream>
using namespace std;

int N, startIdx = -1;
int a[1001];
int d[3];

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(startIdx == -1 && a[i] == 0) startIdx = i;
    }
    // 0 ? ??
    if(startIdx == -1) {
        cout << 0;
        return 0;
    }

    d[0] = 1;
    for(int i = startIdx+1; i < N; i++) {
        int milk = a[i];
        int prev = milk - 1 < 0 ? 2 : milk - 1;

        if(d[prev] == 0) continue;
        d[milk] = max(d[milk], d[prev] + 1);
    }

    cout << max(d[0], max(d[1], d[2]));
}