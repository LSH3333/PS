#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int N, K;
long long answer;
vector<int> friends[21];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        string str; cin >> str;
        friends[(int) str.size()].push_back(i);
    }

    for(int len = 2; len <= 20; len++) {
        if(friends[len].empty()) continue;

        queue<int> q;
        for (auto x: friends[len]) {
            while(!q.empty() && x-q.front() > K) q.pop();
            answer +=  (long long)q.size();
            q.push(x);
        }
    }

    cout << answer;
}