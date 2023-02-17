#include <iostream>
using namespace std;

#define MAX 1000000
#define MOD 1000000000

int N;

// d[i][j] = i를 2의 멱수의 합으로 나타내는 경우의 수 중 뒤가 pow(2,j) 로 끝나는 경우의 수
int d[MAX+10][22];

int main() {
    cin >> N;

    d[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        int sub = 1;
        for (int j = 0; i-sub >= 0 ; j++) {
            for(int k = 0; k <= j; k++) {
                d[i][j] = (d[i][j] + d[i - sub][k]) % MOD;
            }
            sub *= 2;
        }
    }

    int answer = 0;
    for(int i = 0; i < 22; i++) {
        answer = (answer + d[N][i]) % MOD;
    }
    cout << answer;

}