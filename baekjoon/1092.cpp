#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> crane(N);
    for(int i = 0; i < N; i++) {
        cin >> crane[i];
    }
    cin >> M;
    vector<int> box(M);
    for(int i = 0; i < M; i++) {
        cin >> box[i];
    }

    sort(crane.begin(), crane.end());
    sort(box.begin(), box.end());

    for(auto x : crane) cout << x << ' '; cout << endl;
    for(auto x : box) cout << x << ' '; cout << endl; cout << endl;

    int idx = 0;
    while(idx < M) {
        for(int i = 0; i < N; i++) {
            for(int j = idx; j < M; j++) {
                if(crane[i] >= box[j]) { idx = j + 1; break; }
            }
        }
    }
}