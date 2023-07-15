#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T; cin >> T;
    while(T--) {
        int N, answer=1;
        vector<pair<int,int>> v;

        cin >> N;
        for(int i = 0; i < N; i++) {
            int a,b; cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end());

        int minVal = v.front().second;
        for(int i = 1; i < v.size(); i++) {
            if(v[i].second < minVal) {
                answer++;
                minVal = v[i].second;
            }
        }

        cout << answer << '\n';
    }
}