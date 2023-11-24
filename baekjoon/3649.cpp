#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true) {
        int X, N;
        cin >> X;
        if(cin.eof()) break;
        cin >> N;
        X *= 10000000;
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        if(N < 2) {
            cout << "danger\n";
        }
        else {
            int l = 0, r = N-1;
            bool found = false;
            while(l <= r) {
                if(l == r) {
                    found = false;
                    break;
                }
                if(v[l] + v[r] == X) {
                    found = true;
                    break;
                }

                if(v[l] + v[r] > X) {
                    r--;
                } else {
                    l++;
                }
            }

            if(found) cout << "yes " << v[l] << ' ' << v[r] << '\n';
            else cout << "danger\n";
        }

    }

}