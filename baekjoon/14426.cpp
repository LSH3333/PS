#include <iostream>
#include <unordered_map>
using namespace std;

int N, M, answer;
unordered_map<string, bool> mp;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string S; cin >> S;

        string str;
        for(auto c : S) {
            str.push_back(c);
            mp[str] = true;
        }
    }

    for(int i = 0; i < M; i++) {
        string S; cin >> S;
        if(mp[S]) {
            answer++;
        }
    }

    cout << answer;
}