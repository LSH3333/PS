#include <iostream>
using namespace std;
#define MAX 500010

int N, H;
int upward[MAX]; // 석순
int downward[MAX]; // 종유석
int upSum[MAX];
int downSum[MAX];
int sums[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> H;
    for(int i = 1; i <= N; i++) {
        int h; cin >> h;
        if(i % 2 != 0) { // 석순
            upward[h]++;
        }
        else { // 종유석
            downward[H - h + 1]++;
        }
    }

    // upward 석순
    upSum[H] = upward[H];
    for(int i = H-1; i >= 0; i--) {
        upSum[i] += upward[i] + upSum[i + 1];
    }
    // downward 종유석
    for(int i = 1; i <= H; i++) {
        downSum[i] += downward[i] + downSum[i-1];
    }

    // add
    int minVal = 2000000000;
    int minCnt = 0;
    for(int i = 1; i <= H; i++) {
        sums[i] = downSum[i] + upSum[i];
        minVal = min(minVal, sums[i]);
    }

    for(int i = 1; i <= H; i++) {
        if(sums[i] == minVal) minCnt++;
    }

    cout << minVal << ' ' << minCnt;
}