#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T;

struct Data {
    int i1, i2, i3;
};

bool bfs(const string &s1, const string &s2, const string &s3) {
    vector<vector<bool>> visited(s1.size()+1, vector<bool>(s2.size()+1, false));
    queue<Data> q;
    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int i1 = q.front().i1, i2 = q.front().i2, i3 = q.front().i3;
        q.pop();

        if (i3 == s3.size()) {
            return true;
        }

        if (i1 != s1.size() && s1[i1] == s3[i3] && !visited[i1+1][i2]) {
            q.push({i1 + 1, i2, i3 + 1});
            visited[i1+1][i2] = true;
        }
        if (i2 != s2.size() && s2[i2] == s3[i3] && !visited[i1][i2+1]) {
            q.push({i1, i2 + 1, i3 + 1});
            visited[i1][i2+1] = true;
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        cout << "Data set " << t << ": ";
        if (bfs(s1, s2, s3)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}