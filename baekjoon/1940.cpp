#include <iostream>
#include <algorithm>
using namespace std;

int N, M, answer;
int arr[200010];


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int l = 0, r = N-1;
    while(l < r) {
        int sum = arr[l] + arr[r];

        if(sum == M) {
            answer++;
        }

        if(sum <= M) {
            l++;
        }
        else {
            r--;
        }
    }


    cout << answer;
}