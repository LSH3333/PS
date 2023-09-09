#include <iostream>
using namespace std;

#define MOD 100000
int C, R;
int d[102][102][4];

void Print() {
    for(int k = 0; k < 4; k++) {
        for(int i = 1; i <= R; i++) {
            for(int j = 1; j <= C; j++) {
                cout << d[i][j][k] << ' ';
            } cout << endl;
        }cout<<endl;
    }
}

int main() {
    cin >> C >> R;

    d[1][2][0] = 1;
    d[2][1][1] = 1;

    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            if(j+1 <= C) d[i][j+1][0] = (d[i][j+1][0] + d[i][j][0]) % MOD;
            if(i+1 <= R) d[i+1][j][2] = (d[i+1][j][2] + d[i][j][0]) % MOD;

            if(j+1 <= C) d[i][j+1][3] = (d[i][j+1][3] + d[i][j][1]) % MOD;
            if(i+1 <= R) d[i+1][j][1] = (d[i+1][j][1] + d[i][j][1]) % MOD;

            if(i+1 <= R) d[i+1][j][1] = (d[i+1][j][1] + d[i][j][2]) % MOD;

            if(j+1 <= C) d[i][j+1][0] = (d[i][j+1][0] + d[i][j][3]) % MOD;
        }
    }

    int answer = 0;
    for(int i = 0; i < 4; i++) {
        answer = (answer + d[R][C][i]) % MOD;
    }

    cout << answer % MOD;
}