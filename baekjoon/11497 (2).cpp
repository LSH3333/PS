#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;

    while(T--) {
        int N; cin >> N;
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        vector<int> left, right, res;
        for(int i = 0; i < N; i++) {
            if(i % 2 == 0) {
                left.push_back(v[i]);
            }
            else {
                right.push_back(v[i]);
            }
        }


        for(auto x : left) {
            res.push_back(x);
        }
        for(int i = (int)right.size()-1; i >= 0; i--) {
            res.push_back(right[i]);
        }

        int answer = 0;
        for(int i = 1; i < res.size(); i++) {
            answer = max(answer, abs(res[i] - res[i - 1]));
        }

        cout << answer << '\n';
    }



}