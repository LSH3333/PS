#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
bool visited[10];
vector<int> answer;

bool isPrime(int sum) {

    for(int i = 2; i*i <= sum; i++) {
        if(sum % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int idx, int depth, vector<int> &v, int sum) {
    if(depth == M) {
        if (isPrime(sum)) {
            answer.push_back(sum);
        }
        return;
    }

    for(int i = idx; i < N; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(arr[i]);
        dfs(i, depth + 1, v, sum + arr[i]);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    dfs(0, 0, v, 0);

    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    if (answer.empty()) {
        cout << -1;
    } else {
        for(auto x : answer) {
            cout << x << ' ';
        }
    }

}