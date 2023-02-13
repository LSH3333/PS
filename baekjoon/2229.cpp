#include <iostream>
using namespace std;

int N;
int d[1010];
int a[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        int maxVal = a[i];
        int minVal = a[i];

        for(int j = i; j > 0; j--) {
            maxVal = max(maxVal, a[j]);
            minVal = min(minVal, a[j]);
            d[i] = max(d[i], d[j - 1] + (maxVal - minVal));
        }
    }

    cout << d[N];
}