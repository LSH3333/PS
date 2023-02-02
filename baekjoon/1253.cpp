#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[2010];
int answer;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    for(int i = 0; i < N; i++) {
        int left = 0, right = N-1, n = arr[i];

        while(left < right) {
            int sum = arr[left] + arr[right];
            if(right == i) {
                right--; continue;
            }
            if(left == i) {
                left++; continue;
            }

            if(sum > n) {
                right--;
            }
            else if(sum < n) {
                left++;
            }
            else {
                answer++;
                break;
            }
        }
    }

    cout << answer;
}