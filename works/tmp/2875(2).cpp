#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int team = 0;
    int n = 0, m = 0;
    while(true)
    {
        n += 2; m += 1;
        if((N+M) - (n+m) < K) break;
        if(n > N || m > M) break;
        team++;
    }
    cout << team;
}