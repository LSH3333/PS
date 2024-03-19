#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000
int N;
int d[100010];
int coins[] = {1,2,5,7};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i < 100010; i++) {
        d[i] = INF;
    }

    for(int i = 0; i < 4; i++) {
        int coin = coins[i];

        for(int j = 0; j <= N; j++) {
            if(j-coin < 0) continue;
            d[j] = min(d[j], d[j-coin] + 1);
        }
    }

    cout << d[N];

}