#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000
int N, M, S;
vector<int> edges[MAX + 1];
bool fans[MAX + 1];
bool result;

void dfs(int cur) {
    if(fans[cur] || result) {
        return;
    }

    // ? ?? ?? ??
    if (edges[cur].empty()) {
        result = true;
        return;
    }

    for (auto next: edges[cur]) {
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
    }

    cin >> S;
    for (int i = 0; i < S; i++) {
        int s; cin >> s;
        fans[s] = true;
    }

    dfs(1);

    if (result) {
        cout << "yes";
    } else {
        cout << "Yes";
    }
}