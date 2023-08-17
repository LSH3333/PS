#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int answer;

// true ?? ? ?? ??
bool FindDup(const vector<string> &res) {
    int before = (int)res.size();
    set<string> s;
    for(const auto &x : res) {
        s.insert(x);
    }

    if(before != s.size()) {
        return true;
    }else {
        return false;
    }
}

void dfs(const vector<pair<string,string>> &v,int depth, int goalDepth, int idx,
         vector<string> &res) {

    if (depth == goalDepth) {
        if (!FindDup(res)) {
            answer++;
        }
        return;
    }

    for(int i = idx; i < v.size(); i++) {
        res.push_back(v[i].second);
        dfs(v,  depth+1, goalDepth, i, res);
        res.pop_back();
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--) {
        answer = 0;
        int N; cin >> N;
        vector<pair<string,string>> v;
        map<string,bool> mark;
        for(int i = 0; i < N; i++) {
            string a, b; cin >> a >> b;
            v.push_back({a, b});
        }



        for(int goalDepth = 1; goalDepth <= v.size(); goalDepth++) {
            vector<string> res;
            dfs(v, 0, goalDepth, 0, res);
        }

        cout << answer << '\n';
    }


}