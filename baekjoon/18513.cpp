#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
bool visited[200500000];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    queue<pair<int,int>> q;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        q.push({n, n});
        if(n >= 0) {
            visited[n] = true;
        } else {
            visited[abs(n)+100000000] = true;
        }
    }

    long long answer = 0;
    while (!q.empty()) {
        int cur = q.front().first;
        int root = q.front().second;
        q.pop();

        int idx;
        if(cur-1 >= 0) idx = cur - 1;
        else idx = abs(cur-1) + 100000000;
        if (!visited[idx]) {
            visited[idx] = true;
            q.push({cur - 1, root});
            answer += max(root, cur - 1) - min(root, cur - 1);

            if(--K == 0) {
                break;
            }
        }

        if(cur+1 >= 0) idx = cur + 1;
        else idx = abs(cur+1) + 100000000;
        if (!visited[idx]) {
            visited[idx] = true;
            q.push({cur + 1, root});
            answer += max(root, cur + 1) - min(root, cur + 1);
            if(--K == 0) {
                break;
            }
        }

    }


    cout << answer;
}