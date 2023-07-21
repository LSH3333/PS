#include <iostream>
using namespace std;

#define MAX 1500000

int N;
int T[MAX + 1];
int P[MAX+1];
int d[MAX+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for(int i = 1; i <= N; i++) {
        if(i + T[i] - 1 <= N) {
            d[i+T[i]-1] = max(d[i - 1] + P[i],  d[i+T[i]-1]);
        }
        d[i] = max(d[i], d[i - 1]);
    }

    int answer = 0;
    for(int i = 1; i <= N; i++) {
        answer = max(answer, d[i]);
    }

    cout << answer;
}