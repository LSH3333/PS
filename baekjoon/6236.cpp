#include <iostream>
using namespace std;

int N, M, answer = 1000000000;
int a[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int left = 0, right = 1000000000;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        left = max(left, a[i]);
    }

    while(left <= right) {
        int mid = (left + right) / 2;

        int cur = 0, cnt = 0;
        for(int i = 0; i < N; i++) {
            // 돈 부족
            if(cur < a[i]) {
                cnt++; // 인출
                cur = mid;
            }

            cur -= a[i];
        }

        if(cnt > M) {
            left = mid + 1;
        }
        else {
            answer = min(answer, mid);
            right = mid - 1;
        }
    }

    cout << answer;
}