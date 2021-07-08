#include <iostream>
using namespace std;

bool mark[1002];
int arr[1002];

void dfs(int n) {
    if(mark[n]) return;
    mark[n] = true;

    dfs(arr[n]);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            mark[i] = false;

            cin >> arr[i];
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(!mark[i]) {
                dfs(i);
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}