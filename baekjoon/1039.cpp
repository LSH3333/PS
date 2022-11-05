#include <iostream>
#include <queue>
using namespace std;

bool mark[11][1000001];
string ans = "0";

void bfs(const string &N, int K) {
    queue<pair<string,int>> q;
    q.push({N, 0});

    while (!q.empty()) {
        string s = q.front().first;
        int depth = q.front().second;
        q.pop();

        if(depth == K) {
            if(s > ans) {
                ans = s;
            }
            continue;
        }

        for(int i = 0; i < s.size(); i++) {
            for(int j = i+1; j < s.size(); j++) {
                if(i == j) continue;
                string tmp = s;
                swap(tmp[i], tmp[j]);
                if(mark[depth+1][stoi(tmp)] || tmp.front() == '0') continue;
                mark[depth+1][stoi(tmp)] = true;
                q.push({tmp, depth + 1});
            }
        }
    }
}

int main() {
    string N;
    int K;
    cin >> N >> K;

    bfs(N, K);

    if (ans == "0") {
        cout << -1;
    }
    else {
        cout << ans;
    }
}