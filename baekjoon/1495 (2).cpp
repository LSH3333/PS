#include <iostream>
using namespace std;

int N, S, M;
int d[55][1010];
int v[55];

int main() {
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    d[0][S] = 1;
    for(int i = 1; i <= N; i++) {
        int volume = v[i];
        for(int j = 0; j <= M; j++) {
            if(d[i-1][j] > 0) {
                if(j-volume >= 0) {
                    d[i][j-volume] = 1;
                }
                if(j+volume <= M) {
                    d[i][j+volume] = 1;
                }
            }
        }
    }

    int answer = -1;
    for(int j = 0; j <= M; j++) {
        if(d[N][j] > 0) {
            answer = max(answer, j);
        }
    }

    cout << answer;
}