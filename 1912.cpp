#include <iostream>
using namespace std;

int a[100001];
int d[100001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    d[1] = a[1];

    int ans = d[1];
    for(int i = 2; i <= n; i++) {
        if(d[i-1] + a[i] > a[i]) d[i] = d[i-1] + a[i];
        else d[i] = a[i];

        ans = max(ans, d[i]);
    }

    cout << ans;

}