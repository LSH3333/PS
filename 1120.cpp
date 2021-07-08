#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

string A, B;
int A_len, B_len;

int CompareString(int idx) {
    // string A와 B의 차
    int sub = 0;

    // B[idx]부터 A와 비교
    for(int i = idx; i < idx + A_len; i++) {
        // 다르다면 차++
        if(B[i] != A[i-idx]) sub++;
    }

    return sub;
}

int main() {

    cin >> A >> B;
    A_len = A.length();
    B_len = B.length();

    int res = 51;
    int sub = 0;
    for(int i = 0; i <= B_len - A_len; i++) {
        sub = CompareString(i);
        res = min(res, sub);
    }

    cout << res << '\n';
}