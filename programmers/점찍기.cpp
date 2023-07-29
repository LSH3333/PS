#include <string>
#include <vector>
#include <iostream>

using namespace std;


long long solution(int _k, int _d) {
    long long answer = 0;
    long long k = _k, d = _d;

    long long y = d - (d % k);
    for (long long x = 0; x <= d; x += k) {
        while(x*x+y*y > d*d && y > 0) {
            y -= k;
        }

        answer += (y / k + 1);
    }


    return answer;
}

int main() {
    cout << solution(2,4);
}