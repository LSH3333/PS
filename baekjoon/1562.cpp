#include <iostream>
using namespace std;

#define MOD 1000000000

int N;
// [???][??? ?][??(??????)]
int d[101][11][1 << 10];

int main() {
    cin >> N;

    // 1111111111
    int setBit = (1 << 10) - 1;

    // N=1 ?? ? ? 1~9 ??, 0? ??? ?? ??? ??
    for(int j = 1; j <= 9; j++) {
        d[1][j][1<<j] = 1;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int bit = 0; bit <= setBit; bit++) {
                if(j == 0) {
                    d[i][j][bit | (1 << j)] = (d[i][j][bit | (1 << j)] + d[i-1][1][bit]) % MOD;
                }
                else if(j == 9) {
                    d[i][j][bit | (1 << j)] = (d[i][j][bit | (1 << j)] + d[i-1][8][bit]) % MOD;
                }
                else {
                    // j=1 ?? 1 << 1 = 10 , bit=101 ?? 0,2 ????? ??
                    // bit | (1<<j) = 101 | 010 = 111,
                    // ? ? ??? ??? 0,2(101)? ???? ??? 1(010) ? ???? 0,1,2 ? ????? ??
                    d[i][j][bit | (1 << j)] = (d[i][j][bit | (1 << j)] + d[i-1][j-1][bit]) % MOD;
                    d[i][j][bit | (1 << j)] = (d[i][j][bit | (1 << j)] + d[i-1][j+1][bit]) % MOD;
                }
            }
        }
    }

    // N ??, ??? ?? 0~9 ?? ??
    // setBit = 1111111111 ? ?? ? 0~9 ?? ??? ??? ??
    int answer = 0;
    for(int i = 0; i <= 9; i++) {
        answer = (answer + d[N][i][setBit]) % MOD;
    }

    cout << answer % MOD;
}