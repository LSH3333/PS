#include <iostream>
#include <vector>
using namespace std;

int N, M;
int answer = 100000;
int arr[5010];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 10000;
    while(left <= right) {
        int mid = (left + right) / 2;

        int cnt = 1; // 구간의 수
        int minVal = 100000, maxVal = 0;
        for(int i = 0; i < N; i++) {
            minVal = min(minVal, arr[i]);
            maxVal = max(maxVal, arr[i]);

            if(maxVal - minVal > mid) {
                cnt++;
                minVal = arr[i], maxVal = arr[i];
            }
        }

        if(cnt > M) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            answer = min(answer, mid);
        }
    }

    cout << answer;

}