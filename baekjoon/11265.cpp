#include <iostream>
using namespace std;

#define INF 1000000000

int N, M;
int d[501][501];

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> d[i][j];
            if(d[i][j] == 0) {
                d[i][j] = INF;
            }
        }
    }

    FloydWarshall();

    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(d[a][b] <= c) {
            cout << "Enjoy other party\n";
        }else {
            cout << "Stay here\n";
        }
    }
}