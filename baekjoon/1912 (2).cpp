
#include <iostream>
using namespace std;

#define MAX 100000

int N;
int a[MAX+1];
int d[MAX+1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    d[0] = a[0];
    for(int i = 1; i < N; i++) {
        d[i] = max(d[i - 1] + a[i], a[i]);
    }

    int answer = a[0];
    for(int i = 0; i < N; i++) {
        answer = max(answer, d[i]);
    }

    cout << answer;
}