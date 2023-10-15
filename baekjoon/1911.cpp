#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, answer;
vector<pair<int,int>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int last = 0;
    for(auto x : v) {
        int l = x.first, r = x.second;

        int len = r - max(last, l);
        if(len < 0) len = 0;
        int cnt = len % L == 0 ? len/L : len/L+1;
        answer += cnt;
        last = max(last, l) + (L * cnt);
    }

    cout << answer;
}