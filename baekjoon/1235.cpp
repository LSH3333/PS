#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int answer = 0;
    int N; cin >> N;
    vector<string> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for(int k = 1; k <= (int)v.front().size(); k++) {
        set<string> set;

        for(const auto &x : v) {
            string sub = x.substr(x.size()-k);
            set.insert(sub);
        }

        if(set.size() == N) {
            answer = k;
            break;
        }
    }

    cout << answer;
}