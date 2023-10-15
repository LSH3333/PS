#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long total = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long x, a; cin >> x >> a;
        v.push_back({x, a});
        total += a;
    }
    sort(v.begin(), v.end());

    long long sum = 0;
    long long half = total % 2 == 0 ? total/2 : (total+1)/2;
    for(auto item : v) {
        long long x = item.first, a = item.second;
        sum += a;
        if (sum >= half) {
            cout << x;
            break;
        }
    }
}