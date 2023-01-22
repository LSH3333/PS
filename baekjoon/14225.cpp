#include <iostream>
using namespace std;

int N;
int arr[21];
bool mark[21];
bool answer[20000010];

void dfs(int idx,int depth, int goalDepth, int sum) {
    if(depth == goalDepth) {
        answer[sum] = true;
        return;
    }

    for(int i = idx; i < N; i++) {
        if(mark[i]) continue;
        mark[i] = true;
        dfs(i,  depth+1, goalDepth, sum + arr[i]);
        mark[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++) {
        dfs(0, 0, i, 0);
    }

    for(int i = 1; i <= 20000000; i++) {
        if(!answer[i]) {
            cout << i;
            break;
        }
    }
}