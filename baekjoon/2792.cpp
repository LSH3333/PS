#include <iostream>
using namespace std;

#define MAX 300000
int N, M;
int arr[MAX+1];
int answer = 1e9;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    int left = 1, right = 1e9;
    while(left <= right) {
        int mid = (left + right) / 2;

        int cnt = 0;
        for(int i = 0; i < M; i++) {
            int n = arr[i];
            cnt += (n / mid);
            if(n % mid != 0) {
                cnt++;
            }
        }

        if(cnt > N) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
            answer = min(answer, mid);
        }
    }

    cout << answer;
}