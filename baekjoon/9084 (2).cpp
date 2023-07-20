#include <iostream>
using namespace std;

int N,M;
int d[10010];
int coin[110];

int main() {
    int T; cin >> T;
    while(T--) {
        fill(d, d+10010, 0);
        fill(coin, coin+110, 0);
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coin[i];
        }
        cin >> M;

        d[0] = 1;
        for(int i = 0; i < N; i++) {
            for(int j = 1; j <= M; j++) {
                if(j-coin[i] >= 0) {
                    d[j] += d[j - coin[i]];
                }
            }
        }

        cout << d[M] << '\n';
    }
}
