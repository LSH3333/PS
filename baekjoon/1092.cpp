#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> cranes(N);
    for(int i = 0; i < N; i++) {
        cin >> cranes[i];
    }
    cin >> M;
    vector<int> box(M);
    for(int i = 0; i < M; i++) {
        cin >> box[i];
    }

    sort(cranes.begin(), cranes.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());

    vector<bool> mark(M, false);
    int t = 0, cnt = 0;
    while(cnt < M) {
        t++;
        int i = 0;
        bool found = false;
        for(auto crane : cranes) {
            for(; i < M; i++) {
                if(crane >= box[i] && !mark[i]) {
                    mark[i] = true;
                    cnt++; found = true;
                    break;
                }
            }
        }
        if(!found) {
            cout << -1; exit(0);
        }
    }
    cout << t;
}