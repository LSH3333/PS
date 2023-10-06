#include <iostream>
using namespace std;

int N, K, answer;
int arr[200010];
int count[100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int r = 0;
    for(int l = 0; l < N; l++) {
        count[arr[l]]--;
        while(r+1 <= N) {
            if(count[arr[r+1]]+1 > K) {
                break;
            }
            count[arr[r+1]]++;
            r++;
        }

        answer = max(answer, r-l);
    }

    cout << answer;
}