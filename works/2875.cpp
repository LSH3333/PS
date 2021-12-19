#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int cnt = 0;
    while(N>=2 && M>=1 && N+M >= K+3)
    {
        N -= 2;
        M -= 1;
        cnt++;
    }
    cout << cnt;
}