#include <iostream>
using namespace std;

int d[33];

int main()
{
    int N; cin >> N;
    // 홀수는 만들수 있는 경우 없음
    if(N % 2 != 0) { cout << 0; return 0;}

    d[0] = 1;
    for(int i = 2; i <= N; i += 2)
    {
        // d[i-2]인 경우에 3x2 크기 타일들 붙이는 경우
        // 3x2 크기 타일은 3가지 이다.
        d[i] += d[i-2] * 3;
        for(int j = i - 4; j >= 0; j--)
        {
            d[i] += d[j] * 2;
        }
    }

    cout << d[N];
}