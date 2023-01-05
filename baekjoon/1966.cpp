#include <iostream>
#include <deque>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        deque<pair<int,bool>> dq;
        int N, M;
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            int n; cin >> n;
            if(i == M) dq.push_back({n, true});
            else dq.push_back({n, false});
        }

        int cnt = 1;
        while(true) {
            int maxVal = 0;
            for(auto x : dq) {
                maxVal = max(maxVal, x.first);
            }

            auto front = dq.front();
            if(front.first == maxVal) {
                if(front.second) {
                    cout << cnt << '\n';
                    break;
                } else {
                    dq.pop_front();
                }
                cnt++;
            }
            else {
                dq.pop_front();
                dq.push_back(front);
            }
        }
    }
    

}