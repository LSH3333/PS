#include <iostream>
using namespace std;

int N, T;
int studyTime[110];
int score[110];
int d[110][10010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> T;
    for(int i = 1; i <= N; i++) {
        cin >> studyTime[i] >> score[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= T; j++) {
            if(j - studyTime[i] >= 0) {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - studyTime[i]] + score[i]);
            }
            else {
                d[i][j] = d[i - 1][j];
            }
        }
    }

    cout << d[N][T];
}