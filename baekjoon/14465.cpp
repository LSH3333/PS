#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, K, B;
int arr[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K >> B;

    for (int i = 0; i < B; i++) {
        int n; cin >> n;
        arr[n] = 1;
    }

    int sum = 0, answer;
    for(int i = 1; i <= K; i++) {
        sum += arr[i];
    }

    answer = sum;

    int l = 1, r = K;
    while (r+1 <= N) {
        if (arr[l] == 1) {
            sum--;
        }
        l++;

        if(arr[r+1] == 1) {
            sum++;
        }
        r++;

        answer = min(answer, sum);
    }

    cout << answer;
}