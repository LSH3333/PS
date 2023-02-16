#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000
#define MOD 1000000000

int N;

// d[i][j] = i를 2의 멱수의 합으로 나타내는 경우의 수 중 뒤가 pow(2,j) 로 끝나는 경우의 수
int d[MAX+10][22];

int main() {
    cin >> N;

    d[0][0] = 1;
    d[1][0] = 1;

    for(int i = 2; i <= N; i++) {
        for (int j = 0; i-pow(2,j) >= 0 ; j++) {
            int sum = 0;
            for(int k = 0; k <= j; k++) {
                sum += d[i - (int)pow(2,j)][k] % MOD;
            }
            d[i][j] = sum % MOD;
        }
    }

    int answer = 0;
    for(int i = 0; i < 22; i++) {
        answer += d[N][i] % MOD;
    }
    cout << answer % MOD;

}