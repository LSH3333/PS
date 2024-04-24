#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int d[101][101];

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) {
                d[i][j] = 1;
            }
        }
    }
}

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(d[i][k] > 0 && d[k][j] > 0) {
                    d[i][j] = 1;
                }
            }
        }
    }
}

int check() {
    for(int c = 1; c <= N; c++) {
        int sum = 0;
        for(int r = 1; r <= N; r++) {
            sum += d[r][c];
        }
        if(sum == N) {
            return c;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    Init();

    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }

    FloydWarshall();

    cout << check();
}