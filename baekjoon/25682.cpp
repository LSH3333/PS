#include <iostream>
using namespace std;

#define B 0
#define W 1
int N, M, K;
char b[2010][2010];
// black, white
int d[2][2010][2010];
char black[2010][2010], white[2010][2010];
char bw[] = {'B', 'W'};

void MakeBoard() {
    int idx = 0;
    for(int i = 1; i <= N; i++) {
        idx = i%2!=0 ? 0 : 1;
        for(int j = 1; j <= M; j++) {
            black[i][j] = bw[idx];
            white[i][j] = bw[(idx+1)%2];
            idx = (idx + 1) % 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> b[i][j];
        }
    }

    MakeBoard();


    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            // black board
            d[B][i][j] = d[B][i - 1][j] + d[B][i][j - 1] - d[B][i - 1][j - 1];
            if(black[i][j] != b[i][j]) {
                d[B][i][j]++;
            }
            // white board
            d[W][i][j] = d[W][i - 1][j] + d[W][i][j - 1] - d[W][i - 1][j - 1];
            if (white[i][j] != b[i][j]) {
                d[W][i][j]++;
            }
        }
    }


    int answer = 4000000;
    for(int i = K; i <= N; i++) {
        for(int j = K; j <= M; j++) {
            answer = min(answer, d[B][i][j] - (d[B][i][j - K] + d[B][i - K][j]) + d[B][i - K][j - K]);
            answer = min(answer, d[W][i][j] - (d[W][i][j - K] + d[W][i - K][j]) + d[W][i - K][j - K]);
        }
    }

    cout << answer;


}