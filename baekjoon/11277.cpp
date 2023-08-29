#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool d[22];

bool Try(const vector<pair<int,int>> &v) {
    for(auto x : v) {
        bool a = x.first < 0 ? !d[abs(x.first)] : d[abs(x.first)];
        bool b = x.second < 0 ? !d[abs(x.second)] : d[abs(x.second)];

        if(!(a || b)) {
            return false;
        }
    }
    return true;
}

bool dfs(int depth, const vector<pair<int,int>> &v) {
    if(depth == N+1) {
        if (Try(v)) {
            return true;
        }
        else return false;
    }

    d[depth] = true;
    if(dfs(depth+1, v)) {
        return true;
    }

    d[depth] = false;
    if(dfs(depth+1, v)) {
        return true;
    }
    return false;
}




int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector<pair<int,int>> v;
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }

    cout << dfs(1, v);


}