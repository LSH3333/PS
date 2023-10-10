#include <iostream>
using namespace std;

#define INF 10000000
int N, M;
int d[101][101];

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
}

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int GetDist(int chick1, int chick2) {
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        int dist = min(d[i][chick1], d[i][chick2]);
        sum += dist * 2;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ansNode1, ansNode2, ansDist = INF;

    cin >> N >> M;
    Init();
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        d[a][b] = 1;
        d[b][a] = 1;
    }

    FloydWarshall();

    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            int distSum = GetDist(i, j);
            if(distSum < ansDist) {
                ansDist = distSum;
                ansNode1 = i;
                ansNode2 = j;
            }
        }
    }

    cout << ansNode1 << ' ' << ansNode2 << ' ' << ansDist;

}