#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[11][100010];
int d[11][100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
        d[i][0] = arr[i][0];
    }

    for(int c = 1; c < N; c++) {
        for(int r = 0; r < M; r++) {
            int maxVal = 0;
            for(int k = 0; k < M; k++) {
                if(k == r) {
                    maxVal = max(maxVal, d[k][c - 1] + (arr[r][c] / 2));
                } else {
                    maxVal = max(maxVal, d[k][c-1] + arr[r][c]);
                }
            }
            d[r][c] = maxVal;
        }
    }

    int answer = 0;
    for(int r = 0; r < M; r++) {
        answer = max(answer, d[r][N - 1]);
    }

    cout << answer;
}