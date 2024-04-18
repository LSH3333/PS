#include <iostream>
#include <vector>
using namespace std;

int N, K;
int parent[1000010];

void Init() {
    for(int i = 0; i < 1000010; i++) {
        parent[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(true) {
        cin >> N >> K;
        if(N == 0 && K == 0) return 0;
        Init();

        int parent_idx = -1;
        int prev = 0;
        vector<int> nodes;
        for(int i = 0; i < N; i++) {
            int n; cin >> n;

            nodes.push_back(n);

            // ??
            if(i == 0) {
                parent[n] = -1;
                prev = n;
            }
            else {
                // ?? ??
                if(prev + 1 != n) {
                    parent_idx++;
                    parent[n] = nodes[parent_idx];
                    prev = n;
                }
                    // ???
                else {
                    parent[n] = nodes[parent_idx];
                    prev = n;
                }
            }
        }

        int answer = 0;
        // ?? : ?? ??, ??? ??
        for(auto x : nodes) {
            if(parent[K] != parent[x] && parent[parent[K]] == parent[parent[x]]) {
                answer++;
            }
        }

        cout << answer << '\n';
    }


}