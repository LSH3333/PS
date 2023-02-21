#include <iostream>
#include <algorithm>
using namespace std;

#define INF 10000000

int N, M;
int edges[210][210];
int answer[210][210];

void FloydWarshall() {

    for(int k = 1; k <= N; k++) {

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(edges[i][k] + edges[k][j] < edges[i][j]) {
                    edges[i][j] = edges[i][k] + edges[k][j];
                    answer[i][j] = answer[i][k];
                }
            }
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(answer[i][j] == 0) cout << '-' << ' ';
            else cout << answer[i][j] << ' ';
        } cout << '\n';
    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) edges[i][j] = 0;
            else edges[i][j] = INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    Init();
    for(int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(c < edges[a][b]) {
            edges[a][b] = c;
            answer[a][b] = b;
        }
        if(c < edges[b][a]) {
            edges[b][a] = c;
            answer[b][a] = a;
        }
    }


    FloydWarshall();
    Print();
}