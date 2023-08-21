#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 32000

int N, M;
vector<int> edges[MAX+1];
int inDegree[MAX+1];

vector<int> TopologySort() {
    vector<int> answer;
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        answer.push_back(cur);
        q.pop();

        for (const auto &next: edges[cur]) {
            inDegree[next]--;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        edges[a].push_back(b);
        inDegree[b]++;
    }

    vector<int> answer = TopologySort();
    for(const auto &x : answer) {
        cout << x << ' ';
    }
}