#include <iostream>
using namespace std;

int N, M;
long long arr[1000001];
long long answer = 1e12;

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long l = 1, r = 1e12;
    while(l <= r) {
        long long m = (l + r) / 2;

        long long total = 0;
        for(int i = 0; i < N; i++) {
            total += m / arr[i];
        }

        if(total < M) {
            l = m + 1;
        }
        else {
            answer = min(answer, m);
            r = m - 1;
        }
    }

    cout << answer;
}