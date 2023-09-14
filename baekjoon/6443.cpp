#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(const string &str, string &res, vector<bool> &visited) {
    if (res.size() == str.size()) {
        cout << res << '\n';
        return;
    }

    char used = '-';
    for(int i = 0; i < str.size(); i++) {
        if(used != '-' && str[i] == used) continue;
        if(visited[i]) continue;
        used = str[i];
        visited[i] = true;
        res.push_back(str[i]);
        dfs(str, res, visited);
        res.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;

    while(N--) {
        string str;
        cin >> str;

        sort(str.begin(), str.end());

        string res;
        vector<bool> visited(str.size(), false);
        dfs(str, res, visited);
    }




}