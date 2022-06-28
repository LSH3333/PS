#include <iostream>
#define INF 100000000
using namespace std;

int a[1010];
int d[1010];

int main()
{
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];

    d[1] = a[1];
    for(int i = 2; i <= N; i++)
    {
        d[i] = a[i];
        for(int j = i-1; j >= (i/2); j--)
        {
            d[i] = min(d[j] + a[i-j], d[i]);
        }
    }

    cout << d[N];
}