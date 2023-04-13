#include <iostream>
using namespace std;

#define MAX 250
#define INF 10000000
#define ONE_WAY 0

int N, M, K;
int edge[MAX+1][MAX+1];


void Init() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == j) {
                edge[i][j] = 0;
            }
            else {
                edge[i][j] = INF;
            }
        }
    }
}

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(edge[i][k] + edge[k][j] < edge[i][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    Init();
    for(int i = 0; i < M; i++) {
        int u,v,b; cin >> u >> v >> b;
        if(b == ONE_WAY) {
            edge[u][v] = 0;
            edge[v][u] = 1;
        }
        else {
            edge[u][v] = 0;
            edge[v][u] = 0;
        }
    }
    cin >> K;

    FloydWarshall();

    for(int i = 0; i < K; i++) {
        int s, e; cin >> s >> e;
        cout << edge[s][e] << '\n';
    }


}