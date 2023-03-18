#include <iostream>
#include <cmath>
using namespace std;
#define MAX 100000

int N;
int arr[MAX + 1];
int prefixL[MAX + 1];
int prefixR[MAX + 1];

/**
 * 1. 벌 통 벌
 * 2. 벌 벌 통
 * 3. 통 벏 벌
 */

void CalPrefix() {
    int sumR = 0, sumL = 0;
    for(int i = 0; i < N; i++) {
        sumR += arr[i];
        prefixR[i] = sumR;

        sumL += arr[N - i - 1];
        prefixL[N - i - 1] = sumL;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    CalPrefix();


    // 1. 벌 통 벌
    int res1 = (prefixL[1] - prefixL[N/2+1]) +
            (prefixR[N-2] - prefixR[N/2-1]);

    // 2. 벌 벌 통
    int res2 = 0;
    for(int i = 1; i < N-1; i++) {
        res2 = max(res2, prefixL[1] + prefixL[i+1] - arr[i]);
    }

    // 3. 통 벌 벌
    int res3 = 0;
    for(int i = N-2; i >= 1; i--) {
        res3 = max(res3, prefixR[N - 2] + prefixR[i - 1] - arr[i]);
    }

    cout << max(max(res1, res2), res3);
}