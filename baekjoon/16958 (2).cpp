#include <iostream>
#include <vector>
using namespace std;

int N, T, M;
int special[1001];
int cord[1001][2];
int d[1001][1001];

void FloydWarshall() {

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

void Print() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << d[i][j] << ' ';
        } cout << endl;
    } cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T;
    for(int i = 1; i <= N; i++) {
        int s,x,y; cin >> s >> x >> y;
        special[i] = s;
        cord[i][0] = x;
        cord[i][1] = y;
    }


    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) {
                d[i][j] = 0;
                continue;
            }
            // ? ? ??? ??
            if (special[i] == 1 && special[j] == 1) {
                d[i][j] = min(T, abs(cord[i][0] - cord[j][0]) + abs(cord[i][1] - cord[j][1]));
            }
            else {
                d[i][j] = abs(cord[i][0] - cord[j][0]) + abs(cord[i][1] - cord[j][1]);
            }
        }
    }

    FloydWarshall();

    cin >> M;
    for(int i = 0; i < M; i++) {
        int x,y; cin>>x>>y;
        cout << d[x][y] << '\n';
    }
}