#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000
int d[100010][5][5];

int GetPower(int cur, int next) {
    if(cur == 0) {
        return 2;
    } else if(cur == 1) {
        if(next == 1) return 1;
        else if(next == 2 || next == 4) return 3;
        else return 4;
    } else if(cur == 2) {
        if(next == 2) return 1;
        else if(next == 1 || next == 3) return 3;
        else return 4;
    } else if(cur == 3) {
        if(next == 3) return 1;
        else if(next == 2 || next == 4) return 3;
        else return 4;
    } else {
        if(next == 4) return 1;
        else if(next == 1 || next == 3) return 3;
        else return 4;
    }
}

void Init() {
    for (int i = 0; i < 100010; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                d[i][j][k] = INF;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> v;
    while(true) {
        int n; cin >> n;
        if(n == 0) break;
        v.push_back(n);
    }
    int N = (int) v.size();
    if(N == 0) {
        cout << 0; return 0;
    }
    Init();

    d[0][v[0]][0] = 2;
    d[0][0][v[0]] = 2;
    for(int idx = 0; idx < N-1; idx++) {

        for(int i = 0; i <= 4; i++) {
            for(int j = 0; j <= 4; j++) {
                if(d[idx][i][j] == INF) continue;
                int next = v[idx+1];

                // ?? ???
                if (d[idx + 1][next][j] > d[idx][i][j] + GetPower(i, next)) {
                    d[idx + 1][next][j] = d[idx][i][j] + GetPower(i, next);
                }
                // ??? ???
                if (d[idx + 1][i][next] > d[idx][i][j] + GetPower(j, next)) {
                    d[idx + 1][i][next] = d[idx][i][j] + GetPower(j, next);
                }
            }
        }
    }

    int answer = INF;
    for(int i = 0; i <= 4; i++) {
        for(int j = 0; j <= 4; j++) {
            answer = min(answer, d[N - 1][i][j]);
        }
    }
    cout << answer;
}