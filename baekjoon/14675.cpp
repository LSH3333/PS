#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000

int N;
vector<int> edges[MAX+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int q; cin >> q;
    while(q--) {
        int t, k; cin >> t >> k;
        if(t == 1) { // 정점
            // k 노드는 리프 노드 
            if(edges[k].size() == 1) {
                cout << "no\n";
            } else {
                cout << "yes\n";
            }
        }
        else { // 간선
            cout << "yes\n";
        }
    }
}