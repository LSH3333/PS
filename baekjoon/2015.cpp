#include <iostream>
#include <unordered_map>
using namespace std;

long long N, K, answer;
long long pSum[200010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    unordered_map<long long, long long> mp;
    for(int i = 1; i <= N; i++) {
        long long n; cin >> n;
        pSum[i] = pSum[i-1] + n;
    }

    for(int i = 1; i <= N; i++) {
        if(pSum[i] == K) answer++;
        answer += mp[pSum[i] - K];
        mp[pSum[i]]++;
    }

    cout << answer;
}