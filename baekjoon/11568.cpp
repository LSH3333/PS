#include <iostream>
using namespace std;

int N;
int a[1010];
int d[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        int maxVal = 0;
        for(int j = i-1; j >= 0; j--) {
            if(a[j] < a[i]) {
                maxVal = max(maxVal, d[j]);
            }
        }
        d[i] = maxVal + 1;
        answer = max(answer, d[i]);
    }

    cout << answer;
}