#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        auto it = lower_bound(v.begin(), v.end(), n);

        if(it == v.end()) {
            cout << -1 << '\n';
        } else {
            int idx = it - v.begin();
            if(v[idx] == n) {
                cout << idx << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}