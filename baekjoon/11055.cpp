#include <iostream>
using namespace std;

int a[1001];
int d[1001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    d[1] = a[1];
    int ans = a[1];

    for(int i = 2; i <= n; i++) {
        int max_sum = 0;
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i]) {
                max_sum = max(max_sum, d[j]);
            }
        }
        d[i] = max_sum + a[i]; // 자신의 값까지 더한것이 d[i]
        ans = max(ans, d[i]); // 최대값 계속 생신
    }

    cout << ans;
}