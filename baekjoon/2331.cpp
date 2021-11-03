#include <iostream>
using namespace std;
#include <cmath>

int edge[10000000];

int nextnum(int n, int p) {
    int sum = 0;
    while(n != 0) {
        int res = 0;
        res = n % 10;
        sum += pow(res,p);
        n /= 10;
    }
    return sum;
}

int main() {
    int A, P;
    cin >> A >> P;

    int cnt = 1, res = 0;

    while(true) {
        if(edge[A] != 0) {
            res = edge[A]-1;
            break;
        }
        edge[A] = cnt;
        A = nextnum(A,P);
        cnt++;
    }
    cout << res;
}