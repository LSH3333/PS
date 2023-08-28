#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 300000
int N;
int a[MAX+1];
int d[MAX+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    sort(a+1, a+N+1, greater<>());

    for(int i = 1; i <= N; i++) {
        d[i] = a[i] + i;
    }

    int maxVal = 0, cnt = 0;
    for(int i = 1; i <= N; i++) {
        maxVal = max(maxVal, d[i]);
        // ?? 1? ???? ???, ?? ???? ????? ??? ?? ?? ??? ??
        if(a[i] + N < maxVal) {
            cnt++;
        }
    }

    cout << N-cnt;
}