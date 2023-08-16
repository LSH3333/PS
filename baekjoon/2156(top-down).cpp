#include <iostream>
#include <cstring>
using namespace std;

int N;
int a[10010];
int d[10010];

int Find(int i) {
    if(i < 3 || d[i] >= 0) {
        return d[i];
    }

    int res1 = Find(i-2) + a[i];
    int res2 = Find(i-3) + a[i-1] + a[i];
    int res3 = Find(i-1);
    return d[i] = max(res1, max(res2, res3));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        d[i] = -1;
    }

    d[1] = a[1];
    d[2] = a[1] + a[2];

    cout << Find(N);
}