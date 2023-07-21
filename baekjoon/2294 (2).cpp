#include <iostream>
using namespace std;

#define INF 100000000
#define MAX 10000

int N, K;
int coin[MAX+10];
int d[MAX+10];

int main() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> coin[i];
    }
    fill(d, d+MAX+10, INF);
    d[0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= K; j++) {
            if(j-coin[i] >= 0) {
                d[j] = min(d[j], d[j - coin[i]] + 1);
            }
        }
    }

    if(d[K] == INF) {
        cout << -1;
    }
    else {
        cout << d[K];
    }

}