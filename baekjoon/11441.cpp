#include <iostream>
using namespace std;

int N, M;
int a[100001];
int d[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        d[i] = d[i-1] + a[i];
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int l, r; cin >> l >> r;
        cout << d[r] - d[l-1] << '\n';
    }


}