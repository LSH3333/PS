#include <iostream>
using namespace std;

int N,K;
int d[10010];
int coin[110];

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }

    d[0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j-coin[i] >= 0) {
                d[j] += d[j - coin[i]];
            }
        }
    }

    cout << d[K];
}
