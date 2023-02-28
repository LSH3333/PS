#include <iostream>
#include <cstring>
using namespace std;

int d[10010];
int coins[21];

int main() {
    int T; cin >> T;

    while(T--) {
        memset(d, 0, sizeof(d));
        memset(coins, 0, sizeof(coins));

        int N, M; cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> coins[i];
        }
        cin >> M;

        d[0] = 1;

        for(int coinIdx = 0; coinIdx < N; coinIdx++) {
            int coin = coins[coinIdx];
            for(int i = 1; i <= M; i++) {
                if(i-coin >= 0) {
                    d[i] = d[i] + d[i-coin];
                }
            }
        }

        cout << d[M] << '\n';
    }

}