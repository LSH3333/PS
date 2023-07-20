#include <iostream>
using namespace std;

int N, K;
int d[110][100010];
int weight[110];
int value[110];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        int W, V; cin >> W >> V;
        weight[i] = W;
        value[i] = V;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            int v1 = 0, v2 = 0;
            // i?? ?? ???
            if(j-weight[i] >= 0) {
                v1 = d[i-1][j-weight[i]] + value[i];
            }
            // i?? ?? ?? ???
            v2 = d[i-1][j];

            d[i][j] = max(v1, v2);
        }
    }

    int answer = 0;
    for(int i = 0; i <= K; i++) {
        answer = max(answer, d[N][i]);
    }

    cout << answer;

//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= K; j++) {
//            cout << d[i][j] << ' ';
//        } cout << endl;
//    }
}