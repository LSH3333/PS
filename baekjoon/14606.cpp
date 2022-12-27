#include <iostream>
using namespace std;

int d[20];

int main() {
    d[1] = 0;
    d[2] = 1;
    for(int i = 3; i <= 10; i++) {
        int a = (i / 2);
        int b = i - a;
        d[i] = (a * b) + d[a] + d[b];
    }

    int N; cin >> N;
    cout << d[N];
}