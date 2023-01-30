#include <iostream>
using namespace std;

#define MAX 10000000

int N, K;
int a, b;
int order[22];
int dp[22][22][22];
int answer = MAX;


void Init() {
    for(int i = 0; i < 22; i++)
        for(int j = 0; j < 22; j++)
            for(int k = 0; k < 22; k++)
                dp[i][j][k] = MAX;
}

int main() {
    Init();

    cin >> N >> a >> b >> K;
    for(int i = 1; i <= K; i++) {
        cin >> order[i];
    }

    dp[0][a][b] = 0;
    int n = order[1];
    dp[1][n][b] = abs(n-a);
    dp[1][a][n] = abs(n-b);

    for(int depth = 1; depth < K; depth++) {
        n = order[depth+1];

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j || dp[depth][i][j] == MAX) continue;
                dp[depth+1][n][j] = min(dp[depth+1][n][j], dp[depth][i][j] + abs(n-i));
                dp[depth+1][i][n] = min(dp[depth+1][i][n], dp[depth][i][j] + abs(n-j));
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(dp[K][i][j] == MAX) continue;
            answer = min(answer, dp[K][i][j]);
        }
    }
    cout << answer;
}