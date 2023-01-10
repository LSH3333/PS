#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int mark[1000010];

// 구하는것 -> 몇번만에 정렬되는가


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<int> before(N);
    vector<int> after(N);
    for(int i = 0; i <= 1000000; i++) mark[i] = 2000000;
    for(int i = 0; i < N; i++) {
        int n; cin >> n;
        before[i] = n;
        after[i] = n;
        mark[n] = min(mark[n], i);
    }
    sort(after.begin(), after.end());

    int answer = -1;
    for(int i = 0; i < N; i++) {
        int beforeIdx = mark[after[i]];
        answer = max(answer, i-beforeIdx);
    }

    cout << answer+1;
}