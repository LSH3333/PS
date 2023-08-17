#include <iostream>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        map<string, int> m;
        for(int i = 0; i < N; i++) {
            string a, b; cin >> a >> b;
            m[b]++;
        }

        int answer = 1;
        for (const auto &item: m) {
            answer *= item.second + 1;
        }

        cout << answer-1 << '\n';
    }


}