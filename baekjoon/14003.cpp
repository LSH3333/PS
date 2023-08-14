#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int a[1000001];
// idx[i] = j : a[i] ? LIS ? j ??? ??
int idx[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    v.push_back(a[1]);
    idx[1] = 1;
    for(int i = 2; i <= N; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it == v.end()) {
            v.push_back(a[i]);
            idx[i] = (int)v.size();
        }
        else {
            *it = a[i];
            idx[i] = it - v.begin() + 1;
        }
    }

    vector<int> answer;
    int target = (int) v.size();
    for(int i = N; i >= 1; i--) {
        if(idx[i] == target) {
            answer.push_back(a[i]);
            target--;
        }
    }

    cout << answer.size() << '\n';
    for(int i = (int)answer.size()-1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }

}