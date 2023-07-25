#include <iostream>
using namespace std;

int N, K;

bool Cal(int n) {
    int bottles = 0;
    while(n > 0) {
        bottles += (n % 2);
        n /= 2;
    }

    return bottles <= K;
}

int main() {
    cin >> N >> K;

    int n = N;
    while(true) {
        if (Cal(n)) {
            cout << n - N;
            break;
        }
        else {
            n++;
        }
    }
}