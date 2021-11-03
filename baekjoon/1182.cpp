#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s;
vector<int> v;
vector<int> num_idx;
int ans = 0;

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int temp = 1;
    while(temp <= n) {

        // 1 삽입
        for(int i = 0; i < temp; i++) {
            num_idx.push_back(1);
        }
        // 0 삽입
        for(int j = 0; j < n-temp; j++) {
            num_idx.push_back(0);
        }

        do {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                if(num_idx[i] == 1) {
                    sum += v[i];
                    //cout << v[i] << ' ';
                }
            } //cout << endl;
            //cout << sum << endl;
            if(sum == s)
                ans++;
        } while(prev_permutation(num_idx.begin(), num_idx.end()));

        num_idx.clear();
        temp++;
    }

    cout << ans << '\n';

}