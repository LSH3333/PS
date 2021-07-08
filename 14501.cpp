#include <iostream>
#include <algorithm>
#define MAX 16
using namespace std;

int n;
int T[MAX];
int P[MAX];

int ans = 0;

void solve(int cur_day, int total_money) {
    if(cur_day >= n+1) {
        ans = max(ans, total_money);
        return;
    }

    // 해당날에 상담하고, 해당 상담하는데 걸리는 일수만큼 넘어감
    if(cur_day + T[cur_day] <= n + 1)
        solve(cur_day + T[cur_day], total_money + P[cur_day]);
    // 해당날에 상담하지 않고, 그 바로 다음날로 넘어감
    if(cur_day + 1 <= n + 1)
        solve(cur_day + 1, total_money);

}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> T[i] >> P[i];

    solve(1,0);
    cout << ans;
}
