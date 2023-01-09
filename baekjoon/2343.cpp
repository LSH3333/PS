#include <iostream>
using namespace std;

int N, M;
int answer = 1000000000;
int arr[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 1000000000;
    while(left <= right) {
        int mid = (left + right) / 2;

        int sum = 0, cnt = 0;
        int i = 0;
        while(i < N) {
            for(; i < N; i++) {
                sum += arr[i];
                if(sum > mid) break;
            }
            sum = 0;
            cnt++;
            if(cnt > M) break;
        }

        if(cnt <= M) {
            answer = min(answer, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;
}