#include <iostream>
using namespace std;

long long mem[110][110][110];

long long recur(long long a, long long b, long long c) {
    if(a <= 0 || b <= 0 || c <= 0) { return 1; } // memoization

    if(a > 20 || b > 20 || c > 20) {  return recur(20,20,20); }
    if(mem[a][b][c] != 0) {
        return mem[a][b][c];
    }


    if(a < b && b < c) { mem[a][b][c] = recur(a,b,c-1) + recur(a,b-1,c-1) - recur(a, b-1, c); }
    else
    {
        mem[a][b][c] = recur(a-1,b,c) + recur(a-1, b-1, c) + recur(a-1,b,c-1) - recur(a-1, b-1,c-1);
    }
    return mem[a][b][c];


}

int main() {
    while(true) {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << recur(a,b,c) << '\n';
    }
}