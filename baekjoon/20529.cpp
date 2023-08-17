#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 10000000;

int GetDist(const string &mbti1, const string &mbti2) {
    int res = 0;
    for(int i = 0; i < 4; i++) {
        if(mbti1[i] != mbti2[i]) res++;
    }
    return res;
}

void dfs(int idx, int depth, const vector<string> &v, vector<bool> &mark, vector<string> &res) {
    if(depth == 3) {
        int dist = GetDist(res[0], res[1]) +
                   GetDist(res[1], res[2]) + GetDist(res[0], res[2]);
        answer = min(answer, dist);
        return;
    }

    for(int i = idx; i < v.size(); i++) {
        if(mark[i]) continue;
        mark[i] = true;
        res.push_back(v[i]);
        dfs(i, depth+1, v, mark, res);
        mark[i] = false;
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        answer = 100000000;
        int N; cin >> N;
        vector<string> v;
        for(int i = 0; i < N; i++) {
            string s; cin >> s;
            v.push_back(s);
        }

        // 32?? ???? ?? ??? ?? mbti ? ?? 3? ???
        if(N > 32) {
            cout << 0 << '\n';
        }
        else {
            vector<bool> mark(N);
            vector<string> res;
            dfs(0, 0, v, mark, res);

            cout << answer << '\n';
        }

    }


}