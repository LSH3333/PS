#include <iostream>
#include <cmath>
using namespace std;

int N;
long long answer, K;
long long arr[1000001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long l = 1, r = 2000000000;
    while(l <= r) {
        long long mid = (l + r) / 2;
        
        long long totalReq = 0;
        for(int i = 0; i < N; i++) {
            long long req = mid - arr[i];
            if(req > 0) {
                totalReq += req;
            }
        }

        // mid 목표로 레벨 올릴수 있음
        if(totalReq <= K) {
            l = mid + 1;
            answer = max(answer, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << answer;
}