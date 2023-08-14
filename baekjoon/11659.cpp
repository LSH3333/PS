#include <iostream>
using namespace std;

int N, M;
int a[100010];
int d[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    d[1] = a[1];
    for(int i = 2; i <= N; i++) {
        d[i] = d[i-1] + a[i];
    }

    for(int i = 0; i < M; i++) {
        int s,e; cin >> s >> e;
        cout << d[e] - d[s-1] << '\n';
    }
}