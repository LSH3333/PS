#include <iostream>
using namespace std;

int N;
int a[1010];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int maxVal = -1, maxValIdx = -1;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        if(a[i] > maxVal) {
            maxVal = a[i];
            maxValIdx = i;
        }
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {
        if(i == maxValIdx) continue;
        answer += a[i] + maxVal;
    }

    cout << answer;
}