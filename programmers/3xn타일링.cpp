#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MOD 1000000007
long long d[5010];

int solution(int N) {
    int answer = 0;

    // ??? ??? ?? ?? ??
    if(N % 2 != 0) { return 0; }

    d[0] = 1;
    for(int i = 2; i <= N; i += 2)
    {
        // d[i-2]? ??? 3x2 ?? ??? ??? ??
        // 3x2 ?? ??? 3?? ??.
        d[i] = (d[i-2] * 3) % MOD;
        for(int j = i - 4; j >= 0; j-=2)
        {
            d[i] = (d[i] + (d[j] * 2)) % MOD;
        }
    }

    answer = (int)d[N] % MOD;
    return answer;
}

int main() {
    cout << solution(3);
}
