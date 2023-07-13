#include <iostream>
#include <cmath>
using namespace std;

long long answer;
long long N, R, C;

void DivideAndConquer(long long len, long long _r, long long _c, const string& s) {
    if(len == 1) {
        long long l = (int) (pow(2, N-1));
        for(long long i = 0; i < s.size(); i++) {
            int num = (int)(s[i]-'0');
            answer += num * l * l;
            l /= 2;
        }
        return;
    }

    // 0
    if(R < _r + len / 2 && C < _c + len / 2) {
        return DivideAndConquer(len/2, _r, _c, s + "0");
    }
        // 1
    else if(R < _r + len / 2) {
        return DivideAndConquer(len/2, _r, _c + len / 2, s + "1");
    }
        // 2
    else if(C < _c + len / 2) {
        return DivideAndConquer(len/2, _r + len / 2, _c, s + "2");
    }
        // 3
    else {
        return DivideAndConquer(len/2, _r + len / 2, _c + len / 2, s + "3");
    }

}

int main() {
    cin >> N >> R >> C;
    DivideAndConquer((int)(pow(2,N)), 0, 0, "");
    cout << answer;
}