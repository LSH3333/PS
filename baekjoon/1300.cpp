#include <iostream>
using namespace std;

long long N, K;
long long answer;

long long Count(long long mid) {
    long long cnt = 0;

    for(int i = 1; i <= N; i++) {
        if (i * N <= mid) {
            cnt += N;
        }
        else {
            cnt += mid / i;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> K;

    long long left = 1, right = N*N;
    while(left <= right) {
        long long mid = (left + right) / 2;

        long long cnt = Count(mid);

        if(cnt < K) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            answer = mid;
        }
    }

    cout << answer;
}