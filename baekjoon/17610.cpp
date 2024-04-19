#include <iostream>
#include <vector>
using namespace std;

int K, S;
int arr[15];
bool possible[2700000];

void dfs(int idx, int sum) {
//    cout << sum << endl;
    if(sum >= 0) {
        possible[sum] = true;
    }
    if(idx == K) {
        return;
    }

    dfs(idx + 1, sum);
    dfs(idx + 1, sum + arr[idx]);
    dfs(idx + 1, sum - arr[idx]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K;
    for(int i = 0; i < K; i++) {
        cin >> arr[i];
        S += arr[i];
    }

    dfs(0, 0);

    int answer = 0;
    for(int i = 1; i <= S; i++) {
        if(!possible[i]) {
            answer++;
        }
    }

    cout << answer;
}