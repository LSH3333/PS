#include <iostream>
using namespace std;

int N, ansAbs = 2000000000;
int arr[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int l = 0, r = N-1;
    int answer = arr[l] + arr[r];
    while(l < r) {
        if(abs(arr[l] + arr[r]) < ansAbs) {
            ansAbs = abs(arr[l] + arr[r]);
            answer = arr[l] + arr[r];
        }

        if(arr[l] + arr[r] < 0) {
            l++;
        }
        else {
            r--;
        }
    }

    cout << answer;
}