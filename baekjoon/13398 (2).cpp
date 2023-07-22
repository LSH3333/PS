
#include <iostream>
using namespace std;

#define MAX 100000

int N;
int a[MAX+10];
int d[2][MAX+10];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    d[0][0] = a[0];
    d[1][0] = 0;
    for(int i = 1; i < N; i++) {
        d[0][i] = max(d[0][i-1] + a[i], a[i]);
        d[1][i] = max(max(d[0][i - 1], d[1][i - 1]) + a[i], d[0][i - 1]);
    }

    int answer = a[0];
    for(int i = 1; i < N; i++) {
        answer = max(answer, d[0][i]);
        answer = max(answer, d[1][i]);
    }

    cout << answer;


}