#include <iostream>
#include <vector>
using namespace std;

int N, K, answer;
int arr[9];
bool visited[9];

bool Check(const vector<int> &res) {
    int weight = 500;
    for(auto x : res) {
        weight = weight - K + x;
        if(weight < 500) return false;
    }
    return true;
}

void dfs(vector<int> &res) {
    if(res.size() == N) {
        if (Check(res)) {
            answer++;
        }
        return;
    }

    for(int i = 0; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        res.push_back(arr[i]);
        dfs(res);
        visited[i] = false;
        res.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> res;
    dfs(res);

    cout << answer;
}