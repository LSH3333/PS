#include <iostream>
using namespace std;
#include <algorithm>

int dp[101][100001] = {0};
int item[101];
int w[101];

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &w[i], &item[i]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            int put = dp[i-1][j-w[i]] + item[i];
            if(w[i] > j) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(put, dp[i-1][j]);
            }
        }
    }
/*
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            cout << dp[i][j] << ' ';
        }cout << endl;
    }
*/
    cout << dp[n][k];

}