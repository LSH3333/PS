#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[10001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    long long answer = 0;
    if(N % 2 == 0) {
        for(int i = 0; i < N/2; i++) {
            answer = max(answer, arr[i] + arr[N-1-i]);
        }
    }
    else {
        answer = max(answer, arr[N - 1]);
        for(int i = 0; i < N/2; i++) {
            answer = max(answer, arr[i] + arr[N-2-i]);
        }
    }

    cout << answer;
}