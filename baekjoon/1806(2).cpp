#include <iostream>
using namespace std;

int N, S;
int arr[100001];
int answer = 200000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    int sum = arr[0];
    while(left <= right && right < N) {
        if(sum >= S) {
            answer = min(answer, right-left+1);
            sum -= arr[left++];
        }
        else {
            sum += arr[++right];
        }
    }

    if(answer == 200000) cout << 0;
    else cout << answer;
}