#include <iostream>
using namespace std;
#include <algorithm>

int d[1001];
int a[1001];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    reverse(a+1, a+n+1);

    d[1] = 1;

    pair<int, int> memo = make_pair(0,0);
    for(int i = 2; i <= n; i++) {
        int memo = 0; // memorize the biggest value
        for(int j = 1; j < i; j++) {
            if(a[j] < a[i] && d[j] > memo) {
                memo = d[j];
            }
        }
        d[i] = memo + 1;
    }

    cout << *max_element(d, d+n+1);

}