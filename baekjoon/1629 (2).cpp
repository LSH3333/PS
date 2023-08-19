#include <iostream>
using namespace std;

long long A, B, C;


long long Cal(long long n) {
    if(n == 1) {
        return A % C;
    }

    long long res = Cal(n/2);

    if(n % 2 == 0) {
        return (res * res) % C;
    }
    else {
        return (((res * res) % C) * A) % C;
    }
}

int main() {
    cin >> A >> B >> C;
    cout << Cal(B);
}