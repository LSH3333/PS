#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N, K;
int A, B;
string codes[1010];
vector<int> edges[1010];
bool visited[1010];

bool isHamming(string &a, string &b) {
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }
    return cnt == 1;
}

bool bfs() {
    queue<pair<int,string>> q;
    q.push({A, to_string(A)});
    visited[A] = true;

    while (!q.empty()) {
        int curNode = q.front().first;
        string path = q.front().second;
        q.pop();

        if (curNode == B) {
            cout << path;
            return true;
        }

        for (auto next: edges[curNode]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push({next, path + " " + to_string(next)});
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> codes[i];
    }
    cin >> A >> B;

    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if (isHamming(codes[i], codes[j])) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }

    if (!bfs()) {
        cout << -1;
    }
}