#include <iostream>
using namespace std;

#define MAX 1000001
int N, K, answer=MAX;
int arr[1000001];

bool Cal(int len) {
    int cnt = 0;
    for(int i = 0; i < len; i++) {
        if(arr[i] == 1) cnt++;
    }
    if(cnt >= K) return true;

    for(int i = len; i < N; i++) {
        if(arr[i] == 1) {
            cnt++;
        }
        if(arr[i-len] == 1) {
            cnt--;
        }

        if(cnt >= K) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 1, r = 1000000;
    while(l <= r) {
        int m = (l + r) / 2;

        // len=m ?? k ? ??? 1 ??? : ?? ????
        if(Cal(m)) {
            r = m - 1;
            answer = min(answer, m);
        } else {
            l = m + 1;
        }
    }

    if(answer == MAX) {
        answer = -1;
    }
    cout << answer;
}