#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long, long long>> v;
long long prefixSum[100001];
long long answer=1000000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        long long x, a; cin >> x >> a;
        v.push_back({x, a});
    }
    sort(v.begin(), v.end());

    // 누적합
    prefixSum[1] = v.front().second;
    for(int i = 2; i <= N; i++) {
        prefixSum[i] = prefixSum[i-1] + v[i-1].second;
    }

    // 이분 탐색
    long long l = 1, r = N;
    while(l <= r) {
        long long mid = (l + r) / 2;

        long long leftSide = prefixSum[mid];
        long long rightSide = prefixSum[N] - prefixSum[mid];

        if (leftSide >= rightSide) {
            r = mid - 1;
            answer = min(answer, v[mid-1].first);
        } else {
            l = mid + 1;
        }
    }

    cout << answer;
}