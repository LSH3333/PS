#include <iostream>
using namespace std;

#define INF 100000

int N, M, R;
int answer;
int dist[110][110];
int item[110];

void Init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
}

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    Init();
    for(int i = 1; i <= N; i++) {
        cin >> item[i];
    }
    for(int i = 0; i < R; i++) {
        int a, b, l; cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }


    FloydWarshall();

    for(int i = 1; i <= N; i++) {
        int res = 0;
        for(int j = 1; j <= N; j++) {
            if(dist[i][j] <= M) {
                res += item[j];
            }
        }
        answer = max(answer, res);
    }

    cout << answer;

}