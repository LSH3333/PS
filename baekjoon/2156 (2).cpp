#include <iostream>
using namespace std;

int N;
int a[10010];
int d[10010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    d[1] = a[1];
    d[2] = a[1] + a[2];
    if(N < 3) {
        cout << d[2];
        return 0;
    }

    for(int i = 3; i <= N; i++) {
        d[i] = max(d[i - 1], max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]));
    }

    int answer = max(max(d[N], d[N-1]), d[N-2]);
    cout << answer;
}