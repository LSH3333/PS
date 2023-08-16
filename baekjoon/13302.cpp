#include <iostream>
using namespace std;

#define INF 10000000
int N, M;
bool a[110];
int d[110][110];

int Find(int i, int coupon) {
    // ??
    if(i > N) {
        return 0;
    }
    // ?? ??
    if(d[i][coupon] != INF) {
        return d[i][coupon];
    }
    // ??? ?? ?
    if(a[i]) {
        return d[i][coupon] = Find(i+1, coupon);
    }

    int r1 = Find(i + 1, coupon) + 10000;
    int r2 = Find(i + 3, coupon + 1) + 25000;
    int r3 = Find(i + 5, coupon + 2) + 37000;
    int r4 = INF;
    if(coupon >= 3) {
        r4 = Find(i + 1, coupon-3);
    }
    int minR = min(r1, min(r2, min(r3, r4)));
    return d[i][coupon] = min(d[i][coupon], minR);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int n; cin >> n;
        a[n] = true;
    }

    for(int i = 0; i < 110; i++) {
        for(int j = 0; j < 110; j++) {
            d[i][j] = INF;
        }
    }

    cout << Find(1, 0);

}