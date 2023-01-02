#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[110];
bool mark[110];

bool dfs(int node, int startNode, vector<int> &v) {
    if(node == startNode && mark[node]) {
        return true;
    }
    if(mark[node]) {
        return false;
    }
    mark[node] = true;
    v.push_back(node);
    return dfs(arr[node], startNode, v);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    set<int> answer;
    for(int i = 1; i <= N; i++) {
        memset(mark, false, sizeof(mark));
        vector<int> v;
        bool res = dfs(i, i, v);
        if(res) {
            for(auto x : v) {
                answer.insert(x);
            }
        }
    }

    cout << answer.size() << '\n';
    for(auto x : answer) cout << x << '\n';
}