#include <iostream>
using namespace std;

int N;
int card[2010][2];
int answer;

// i : 카드의 깊이
// j : LEFT or RIGHT
// dp[2][3] = 10 이라면 왼쪽 카드는 2번째 카드, 오른쪽 카드는 3번째, 그때의 점수는 10점
int dp[2010][2010];

#define LEFT 0
#define RIGHT 1

void Init() {
    for(int i = 0; i < 2010; i++) {
        for(int j = 0; j < 2010; j++) {
            dp[i][j] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();
    cin >> N;
    // LEFT CARD
    for(int i = 1; i <= N; i++) {
        cin >> card[i][LEFT];
    }
    // RIGHT CARD
    for(int i = 1; i <= N; i++) {
        cin >> card[i][RIGHT];
    }

    // 최초에
    // 왼쪽 카드를 버림
    dp[2][1] = 0;
    // 양쪽 카드를 버림
    dp[2][2] = 0;
    // 오른쪽 카드가 더 작다면 오른쪽 카드를 버림
    if(card[1][LEFT] > card[1][RIGHT]) {
        dp[1][2] = card[1][RIGHT];
        answer = max(answer, dp[1][2]);
    }


    // DP
    for(int i = 1; i <= N; i++) { // LEFT
        for(int j = 1; j <= N; j++) { // RIGHT
            if(dp[i][j] < 0) continue;

            // 왼쪽 카드 버림
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            answer = max(answer, dp[i + 1][j]);

            // 양쪽 카드 버림
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
            answer = max(answer, dp[i + 1][j + 1]);

            // 오른쪽 카드가 더 작다면 오른쪽 카드를 버림
            if(card[i][LEFT] > card[j][RIGHT]) {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + card[j][RIGHT]);
                answer = max(answer, dp[i][j + 1]);
            }
        }
    }

    cout << answer;

}