#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long N, M, answer;
int arr[1000010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long l = 1, r = 1000000000;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(mid == 0) break;
//        cout << l << ' ' << mid << ' ' << r << endl;
        long long cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += arr[i] / mid;
            if(cnt >= M) break;
        }

        // ???? ??
        if(cnt >= M) {
            answer = mid;
            l = mid + 1;
        }
            // ???
        else {
            r = mid - 1;
        }
    }

    cout << answer;
}