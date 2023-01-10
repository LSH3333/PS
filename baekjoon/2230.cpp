#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int arr[100010];
int answer = 2000000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int left = 0, right = 0;
    while(right < N) {
        int sub = arr[right] - arr[left];

        if(sub >= M) {
            answer = min(answer, sub);
            if(answer == M) break;
            left++;
        }
        else {
            right++;
        }
    }

    cout << answer;
}