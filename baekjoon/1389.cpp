#include <iostream>
using namespace std;

#define INF 10000000

int N, M;
int mark[110][110];

void Init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            mark[i][j] = INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    Init();
    for(int i = 0; i < M; i++) {
        int a,b; cin >> a >> b;
        mark[a][b] = 1;
        mark[b][a] = 1;
    }

    // floyd warshall
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (mark[i][j] > mark[i][k] + mark[k][j]) {
                    mark[i][j] = mark[i][k] + mark[k][j];
                }
            }
        }
    }

    int answer = INF, maxSum = INF;
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            if(i == j) continue;
            sum += mark[i][j];
        }
        if(sum < maxSum) {
            maxSum = sum;
            answer = i;
        }
    }

    cout << answer;
}