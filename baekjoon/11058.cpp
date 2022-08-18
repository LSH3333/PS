#include <iostream>
using namespace std;

long long d[101];

int main()
{
    int N; cin >> N;

    d[1] = 1; d[2] = 2; d[3] = 3;
    for(int i = 1; i <= N; i++)
    {
        d[i] = max(d[i-1]+1, (long long)i);
        for(int j = i-3; j >= 1; j--)
        {
            d[i] = max(d[i], d[j] * (i - j - 1));
        }
    }

    cout << d[N];

}