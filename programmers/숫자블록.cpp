#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long Cal(long long n) {
    if(n == 1) return 0;
    long long res = 1;

    for(long long i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            res = i;

            if(n / i <= 10000000) {
                res = n / i;
                return res;
            }
        }
    }

    return res;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for(long long n = begin; n <= end; n++){
        answer.push_back((int)Cal(n));
    }

    return answer;
}

int main() {
    solution(1, 10);
}