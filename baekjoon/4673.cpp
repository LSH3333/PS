#include <iostream>
using namespace std;

bool mark[10001];

int getSN(int n) {
    int sum = n;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    for(int i = 1; i <= 10000; i++) {
        int sn = getSN(i);
        mark[sn] = true;
    }

    for(int i = 1; i <= 10000; i++) {
        if(!mark[i]) cout << i << '\n';
    }
}