#include <iostream>
using namespace std;

#define MOD 1000000000

int d[10][101];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= 9; i++) {
        d[i][1] = 1;
    }

    for(int c = 2; c <= N; c++) {
        for(int r = 0; r <= 9; r++) {
            if(r == 0) {
                d[r][c] = d[r+1][c-1] % MOD;
            }
            else if(r == 9) {
                d[r][c] = d[r-1][c-1] % MOD;
            }
            else {
                d[r][c] = (d[r+1][c-1] + d[r-1][c-1]) % MOD;
            }
        }
    }

    int answer = 0;
    for(int r = 0; r <= 9; r++) {
        answer = (answer + d[r][N]) % MOD;
    }
    cout << answer;
}