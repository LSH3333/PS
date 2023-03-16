#include <iostream>
using namespace std;

int N, M;
int edges[1010][1010];

#define INF 100000000

void Init() {
    for(int i = 0; i < 1010; i++) {
        for(int j = 0; j < 1010; j++) {
            if(i == j) edges[i][j] = 1;
            else edges[i][j] = INF;
        }
    }
}

void FloydWarshall() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) continue;
                if(edges[i][k] + edges[k][j] < edges[i][j]) {
                    edges[i][j] = edges[i][k] + edges[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Init();

    cin >> N >> M;
    for(int i = 0; i < N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }

    FloydWarshall();

    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        cout << edges[a][b] << '\n';
    }
    
}