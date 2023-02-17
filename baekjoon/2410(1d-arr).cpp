#include <iostream>
using namespace std;

#define MAX 1000000
#define MOD 1000000000

int N;
int d[MAX + 10];

int main() {
    cin >> N;

    d[0] = 1;
    int sub = 1;
    while(sub <= MAX) {

        for(int i = 1; i <= N; i++) {
            if(i-sub >= 0) {
                d[i] = (d[i] + d[i-sub]) % MOD;
            }
        }

        sub *= 2;
    }

    cout << d[N];
}