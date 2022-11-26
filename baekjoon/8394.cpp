#include <iostream>
using namespace std;

int N;
int d[10000010];

int main() {
    cin >> N;
    d[1] = 1;
    d[2] = 2;
    for(int i = 3; i <= N; i++) {
        d[i] = (d[i - 1] + d[i - 2]) % 10;
    }
    cout << d[N];
}