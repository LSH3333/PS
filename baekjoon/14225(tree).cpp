#include <iostream>
using namespace std;

int N;
int arr[21];
bool answer[20000010];

void dfs(int idx, int sum) {
    if(idx == N) {
        answer[sum] = true;
        return;
    }

    dfs(idx+1, sum);
    dfs(idx+1, sum + arr[idx]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dfs(0, 0);

    for(int i = 1; i <= 20000000; i++) {
        if(!answer[i]) {
            cout << i;
            break;
        }
    }
}