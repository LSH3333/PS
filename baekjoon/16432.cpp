#include <iostream>
#include <vector>
using namespace std;

int N;
int b[1010][10];
bool d[1010][10];
bool res;

void dfs(int r, vector<int> &v) {
    if(res) {
        return;
    }
    if(r == N+1) {
        for(auto x : v) {
            cout << x << '\n';
        }
        res = true;
        return;
    }

    for(int c = 0; c < 9; c++) {
        int cake = b[r][c];
        if(res) return;
        if(cake == 0) break;
        if (v.empty()) {
            d[r+1][cake] = true;
            v.push_back(cake);
            dfs(r + 1, v);
            v.pop_back();
        }
        else {
            if(b[r][c] == v.back() || d[r+1][cake]) continue;
            d[r+1][cake] = true;
            v.push_back(b[r][c]);
            dfs(r + 1, v);
            v.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int n; cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> v;
    dfs(1, v);

    if(!res) {
        cout << -1;
    }
}