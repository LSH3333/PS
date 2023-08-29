#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    while(N--) {
        int T; cin >> T;
        unordered_map<long long, long long> mp;
        long long maxKey=0, maxVal=0;
        for(int i = 0; i < T; i++) {
            long long key; cin >> key;
            mp[key]++;
            long long val = mp[key];
            if(val > maxVal) {
                maxKey = key;
                maxVal = val;
            }
        }

        if(maxVal > T / 2) {
            cout << maxKey << '\n';
        } else {
            cout << "SYJKGW\n";
        }
    }

}