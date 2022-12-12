#include <iostream>
using namespace std;

int C, N;
int cost[1010];
int ppl[1010];
int d[21][100010];
int answer = 2000000000;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> C >> N;
    for(int i = 1; i <= N; i++) {
        cin >> cost[i] >> ppl[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < 100010; j++) {
            if(j-cost[i] >= 0) {
                d[i][j] = max(d[i-1][j], d[i][j-cost[i]] + ppl[i]);
            }
            else {
                d[i][j] = d[i-1][j];
            }

            if(d[i][j] >= C) {
                answer = min(answer, j);
            }
        }
    }
    
    cout << answer;
}