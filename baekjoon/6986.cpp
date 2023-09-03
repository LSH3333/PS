#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int N, K;
double scores[100010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    sort(scores, scores + N);

    // 절사 평균
    double total = 0;
    for(int i = K; i < N-K; i++) {
        total += scores[i];
    }
    double answer = total / (N - K * 2);
    cout << fixed << setprecision(2) << floor(answer * 100 + 0.5) / 100 << '\n';

    // 보정 평균
    total = 0;
    for(int i = 0; i < N; i++) {
        if(i < K) {
            total += scores[K];
        }
        else if(i >= N-K) {
            total += scores[N-K-1];
        }
        else {
            total += scores[i];
        }
    }

    answer = (double) (total / N);
    cout << fixed << setprecision(2) << floor(answer * 100 + 0.5) / 100;
}