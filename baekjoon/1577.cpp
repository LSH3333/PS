#include <iostream>
using namespace std;

#define TOP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// 세로 가로
int N, M;
int K;
// true 시 해당 방향 도로 막혀 있음
bool road[101][101][4];
long long dp[101][101];

void MakeRoad(int r1, int c1, int r2, int c2) {
    int rSub = r2-r1;
    if(r1+c1 > r2+c2) {
        if(rSub == 0) {
            road[r1][c1][LEFT] = true;
            road[r2][c2][RIGHT] = true;
        }
        else {
            road[r1][c1][TOP] = true;
            road[r2][c2][DOWN] = true;
        }
    }
    else {
        if(rSub == 0) {
            road[r1][c1][RIGHT] = true;
            road[r2][c2][LEFT] = true;
        }
        else {
            road[r1][c1][DOWN] = true;
            road[r2][c2][TOP] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    for(int i = 0; i < K; i++) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        MakeRoad(b, a, d, c);
    }


    dp[0][0] = 1;
    for(int r = 0; r <= N; r++) {
        for(int c = 0; c <= M; c++) {
            // from top
            if(r-1 >= 0 && !road[r][c][TOP]) {
                dp[r][c] += dp[r-1][c];
            }
            // from left
            if (c - 1 >= 0 && !road[r][c][LEFT]) {
                dp[r][c] += dp[r][c-1];
            }
        }
    }

    cout << dp[N][M];
    
}