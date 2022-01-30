#include <iostream>
using namespace std;

// 5의 갯수
long long Cal(long long n, long long div)
{
    long long cnt = 0;
    while(n > 0)
    {
        n /= div;
        cnt += n;
    }
    return cnt;
}


int main()
{
    long long n, m;
    cin >> n >> m;

    // 나눴을때 0의 갯수는 분모의 0갯수 - 분자의 0갯수
    long long a = Cal(n,2) - (Cal(m,2) + Cal(n-m,2));
    long long b = Cal(n, 5) - (Cal(m,5) + Cal(n-m, 5));
    cout << min(a,b);
}