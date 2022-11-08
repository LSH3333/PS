#include <iostream>
using namespace std;

int K, C;

bool Check(int m, int n) {
    int left = K - max(m, n);
    if(min(m,n) + left < max(m, n)) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K >> C;
    while(C--) {
        int M, N; cin >> M >> N;
        int left = K - max(M, N);

        if(M == N) {
            cout << 1 << '\n'; continue;
        }
        if(M > N) {
            if(abs(M-N) - left <= 2) {
                cout << 1 << '\n'; continue;
            }
            else {
                cout << 0 << '\n'; continue;
            }
        }
    }

}