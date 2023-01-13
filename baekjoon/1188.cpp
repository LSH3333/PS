#include <iostream>
using namespace std;

int N, M, answer;

int GCD(int a, int b) {
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main() {
    cin >> N >> M;
    int gcd = GCD(N, M); // 최대공약수

    answer = M - gcd;

    cout << answer;
}