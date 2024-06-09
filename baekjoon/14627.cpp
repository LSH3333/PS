#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000
long long S, C;
long long arr[MAX + 1];

int main() {
    cin >> S >> C;
    for(int i = 0; i < S; i++) {
        cin >> arr[i];
    }

    long long maxLen = 0;
    long long l = 1, r = 1000000000;
    while(l <= r) {
        long long mid = (l + r) / 2;
//        cout << l << ' ' << mid << ' ' << r << endl;
        long long cnt = 0;
        for(int i = 0; i < S; i++) {
            cnt += (long long)arr[i] / mid;
        }

        if(cnt >= C) {
            maxLen = max(maxLen, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }


    //
    long long answer = 0;
    for(int i = 0; i < S; i++) {
        answer += arr[i];
    }

    cout << answer - maxLen * C;
}