#include <iostream>
#include <vector>
using namespace std;

int N, M, answer;

int main() {
    vector<int> v;

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        if(n % 10 == 0) {
            int cnt = n / 10;
            if(M - (cnt-1) >= 0) {
                M -= (cnt-1);
                answer += cnt;
            } else {
                answer += M;
                M -= (cnt-1);
            }
        }
        else {
            v.push_back(n);
        }
    }

    for(auto n : v) {
        int cnt = n / 10;
        if(M - cnt >= 0) {
            M -= cnt;
            answer += cnt;
        } else {
            answer += M;
            break;
        }
    }

    cout << answer;
}