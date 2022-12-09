#include <iostream>
using namespace std;

int N, M;
int page[210];
int day[210];
// i번째 물건까지 확인했을때, j 일 까지 읽을수 있는 최대 페이지 수
int d[21][210];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> day[i] >> page[i];
    }

    // 챕터
    for(int i = 1; i <= M; i++) {
        // 일수
        for(int j = 1; j <= N; j++) {
            if(j-day[i] >= 0) {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - day[i]] + page[i]);
            }
            else {
                d[i][j] = d[i-1][j];
            }
        }
    }

    cout << d[M][N];
}