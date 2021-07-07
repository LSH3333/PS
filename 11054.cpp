#include <iostream>
using namespace std;
#include <algorithm>

int a[1001];
int up[1001];
int down[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    up[1] = 1;
    down[n] = 1;

    // up
    for(int i = 1; i <= n; i++){
        int memo = 0;
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i] && memo < up[j]) {
                memo = up[j];
            }
            up[i] = memo + 1;
        }
    }

    // down
    for(int i = n; i >= 1; i--) {
        int memo = 0;
        for(int j = n; j > i; j--) {
            if(a[j] < a[i] && memo < down[j]) {
                memo = down[j];
            }
            down[i] = memo + 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, up[i] + down[i]);
    }
    cout << ans-1;

}