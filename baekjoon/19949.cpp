#include <iostream>
using namespace std;

int answer;
int arr[10];
int pick[10];

void dfs(int idx, int sum) {
    if(idx == 10) {
        if(sum >= 5) answer++;
        return;
    }

    for(int i = 1; i <= 5; i++) {
        if(idx >= 2 && i == pick[idx-1] && i == pick[idx-2]) {
            continue;
        }
        pick[idx] = i;
        if (i == arr[idx]) {
            dfs(idx+1, sum+1);
        } else {
            dfs(idx+1, sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    dfs(0,0);
    cout << answer;
}