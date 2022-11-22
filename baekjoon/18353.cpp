#include <iostream>
using namespace std;

int a[2010];
int d[2010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    d[0] = 1;
    int maxVal = 1;
    for(int i = 1; i < N; i++) {
        for(int j = i-1; j >= 0; j--) {
            if(a[j] > a[i]) {
                d[i] = max(d[i], d[j]);
            }
        }
        d[i]++;
        maxVal = max(maxVal, d[i]);
    }

    cout << N-maxVal;
}