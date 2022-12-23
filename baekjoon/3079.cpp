#include <iostream>
#include <climits>
using namespace std;

long long N, M;
long long arr[100001];
long long answer = LONG_MAX;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    long long minTime = 2000000000;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        minTime = min(minTime, arr[i]);
    }

    long long left = 1, right = minTime * M;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        
        for(int i = 0; i < N; i++) {
            sum += mid / arr[i];
        }

        if(sum < M) {
            left = mid+1;
        }
        else {
            answer = min(answer, mid);
            right = mid-1;
        }
    }

    cout << answer;
}